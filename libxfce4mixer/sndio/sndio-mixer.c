/*
 * Copyright (C) 2020 Landry Breuil <landry@xfce.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <sndio.h>
#include <poll.h>
/* needed for g_unix_fd_source_new () */
#include <glib-unix.h>

#include <libxfce4ui/libxfce4ui.h>

#include "sndio-mixer.h"
#include "sndio-track.h"
#include "sndio-options.h"

/* globals */
struct _GstMixerSndio
{
  GstMixer parent;
  struct sioctl_hdl *hdl;
  struct pollfd pfd;
  GSource *src;
  GHashTable *tracks;
  GHashTable *tracks_by_addr;
};

G_DEFINE_TYPE (GstMixerSndio, gst_mixer_sndio, GST_TYPE_MIXER)

/* sndio callbacks */
void
onval(void *arg, unsigned addr, unsigned val)
{
  GstMixerSndio *mixer = GST_MIXER_SNDIO (arg);
  mixer = NULL;
  g_print("onval called: addr=%d, val=%d\n", addr, val);
}

/* callback called when a description changes - e.g when a new track is added/removed */
void
ondesc(void *arg, struct sioctl_desc *d, int curval)
{
  
  GstMixerSndioTrack *track;
  int chan, nchan;
  GstMixerTrackFlags flags = 0;
  GstMixerSndio *mixer = GST_MIXER_SNDIO (arg);
  if (d == NULL) {
    g_debug("got the full set of track descriptions");
    return;
  }
  g_debug("ondesc callback called: addr=%d, %s/%s.%s[%d]=%d (max=%d)", d->addr, d->group, d->node0.name, d->func, d->node0.unit, curval, d->maxval);
  if (d->node0.unit == -1 ) {
    nchan = 1;
    chan = 0;
  } else {
    nchan = 2;
    chan = d->node0.unit;
  }

  /* skip server.device for now */
  if (!g_strcmp0 (d->func, "device"))
    return;

  track = g_hash_table_lookup(mixer->tracks, d->node0.name);
  if (!track) {
    track = gst_mixer_sndio_track_new ();

    if (! g_strcmp0(d->node0.name, "input"))
      flags |= GST_MIXER_TRACK_INPUT;
    else
      flags |= GST_MIXER_TRACK_OUTPUT;

    if (! g_strcmp0(d->node0.name, "output"))
      flags |= GST_MIXER_TRACK_MASTER;

    GST_MIXER_TRACK(track)->index = 0;
    GST_MIXER_TRACK(track)->min_volume = 0;
    GST_MIXER_TRACK(track)->max_volume = d->maxval;
    GST_MIXER_TRACK(track)->has_volume = TRUE;
    GST_MIXER_TRACK(track)->has_switch = FALSE;
    GST_MIXER_TRACK(track)->label = g_strdup(d->node0.name);
    GST_MIXER_TRACK(track)->untranslated_label = g_strdup (d->node0.name);
    GST_MIXER_TRACK(track)->flags = flags;
    GST_MIXER_TRACK(track)->num_channels = nchan;
    GST_MIXER_TRACK(track)->volumes = g_new (gint, nchan);
    track->vol_addr = g_new (gint, nchan);
    track->mute_addr = g_new (gint, nchan);
    g_debug("Inserting new track in hashtable for %s", d->node0.name);
    g_hash_table_insert (mixer->tracks, g_strdup(d->node0.name), track);

    gst_mixer_new_track (GST_MIXER(mixer),
      GST_MIXER_TRACK(track));
  }

  /* now we have a valid track, update volume/mute/recording status */
  if (!g_strcmp0 (d->func, "level")) {
    GST_MIXER_TRACK(track)->volumes[chan] = curval;
    track->vol_addr[chan] = d->addr;
  }
  if (!g_strcmp0 (d->func, "mute")) {
    GST_MIXER_TRACK(track)->has_switch = TRUE;
    track->mute_addr[chan] = d->addr;
    if (IS_INPUT(track)) {
      gst_mixer_track_update_recording(GST_MIXER_TRACK(track), curval);
    } else if (IS_OUTPUT(track)) {
      gst_mixer_track_update_mute(GST_MIXER_TRACK(track), curval);
    }
  }

  /* insert track in tracks_by_addr hash if its not already there */
  if (! g_hash_table_contains(mixer->tracks_by_addr, GINT_TO_POINTER(d->addr)))
    g_hash_table_insert(mixer->tracks_by_addr, GINT_TO_POINTER(d->addr), track);
}

static void
gst_mixer_sndio_finalize (GObject *self)
{
  GstMixerSndio *mixer = GST_MIXER_SNDIO (self);
  mixer = NULL;

  g_hash_table_unref (mixer->tracks_by_addr);
  g_hash_table_unref (mixer->tracks);
  G_OBJECT_CLASS (gst_mixer_sndio_parent_class)->finalize (self);
}


static void
gst_mixer_sndio_init (GstMixerSndio *mixer)
{
  mixer->tracks_by_addr = g_hash_table_new (g_direct_hash, g_direct_equal);
  mixer->tracks = g_hash_table_new (g_str_hash, g_str_equal);
}


static GstMixerFlags
gst_mixer_sndio_get_mixer_flags (GstMixer *mixer)
{
  return GST_MIXER_FLAG_AUTO_NOTIFICATIONS;
}

static void gst_mixer_sndio_set_volume (GstMixer *mixer, GstMixerTrack *track, gint *volumes)
{
  GstMixerSndio *sndio = GST_MIXER_SNDIO (mixer);
  sndio = NULL;
  int i;

  for (i = 0; i < NUM_CHANNELS(track); i++)
    track->volumes[i] = volumes[i];
}


static void
gst_mixer_sndio_get_volume (GstMixer *mixer, GstMixerTrack *track, gint *volumes)
{
  int i;

  for (i = 0; i < NUM_CHANNELS(track); i++)
  {
    volumes[i] = track->volumes[i];
  }
}

static void
gst_mixer_sndio_set_record (GstMixer * mixer, GstMixerTrack *track, gboolean record)
{
  GstMixerSndio *sndio = GST_MIXER_SNDIO (mixer);
  sndio = NULL;
}


static void
gst_mixer_sndio_set_mute (GstMixer *mixer, GstMixerTrack *track, gboolean mute)
{
  GstMixerSndio *sndio = GST_MIXER_SNDIO (mixer);
  sndio = NULL;
}


static const gchar *
gst_mixer_sndio_get_option (GstMixer *mixer, GstMixerOptions *opts)
{
  return NULL;
}


static void
gst_mixer_sndio_set_option (GstMixer *mixer, GstMixerOptions *opts, gchar *value)
{
}


static void
gst_mixer_sndio_class_init (GstMixerSndioClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GstElementClass *element_klass = GST_ELEMENT_CLASS (klass);
  GstMixerClass *mixer_class = GST_MIXER_CLASS (klass);

  gst_element_class_set_static_metadata (element_klass,
                                         "Sndio mixer", "Generic/Audio",
                                         "Control audio mixer via sndio API",
                                         "Landry Breuil <landry@xfce.org>");

  mixer_class->get_mixer_flags = gst_mixer_sndio_get_mixer_flags;
  mixer_class->set_volume  = gst_mixer_sndio_set_volume;
  mixer_class->get_volume  = gst_mixer_sndio_get_volume;
  mixer_class->set_record  = gst_mixer_sndio_set_record;
  mixer_class->set_mute    = gst_mixer_sndio_set_mute;
  mixer_class->get_option  = gst_mixer_sndio_get_option;
  mixer_class->set_option  = gst_mixer_sndio_set_option;

  object_class->finalize = (void (*) (GObject *object)) gst_mixer_sndio_finalize;
}

static gboolean gst_mixer_sndio_src_callback (gint fd, GIOCondition condition, gpointer user_data)
{
  int rc, revents;
  GstMixerSndio *sndio = (GstMixerSndio *)user_data;
  g_print("gst_mixer_sndio_src_callback called with condition %d on fd %d!\n", condition, fd);
  rc = poll(&(sndio->pfd), 1, 0);
  if (rc == 0) {
    g_critical("timeout? cant happen");
    return G_SOURCE_REMOVE;
  } else if (rc == -1) {
    g_critical("poll() error: %s", g_strerror(errno));
    return G_SOURCE_REMOVE;
  } else {
    revents = sioctl_revents(sndio->hdl, &(sndio->pfd));
    g_print("sioctl_revents returned %d, pfd.revents=%d\n", revents, sndio->pfd.revents);
  }
  return G_SOURCE_CONTINUE;
}

GstMixer*
gst_mixer_sndio_new (struct sioctl_hdl *hdl)
{
  GstMixerSndio *sndio;
  char *devname = SIO_DEVANY;
  int rc;

  sndio = g_object_new (GST_MIXER_TYPE_SNDIO,
                        "name", "sndio",
                        "card-name", g_strdup (_("Sndio Volume Control")),
                        NULL);
  sndio->hdl = hdl;
  if (!sioctl_ondesc(hdl, ondesc, sndio)) {
    g_critical("%s: can't get device description", devname);
    return NULL;
  }

  sioctl_onval(sndio->hdl, onval, sndio);
  rc = sioctl_pollfd(sndio->hdl, &(sndio->pfd), POLLIN);
  if (rc != 1) {
    g_critical("[sndio] sioctl_pollfd failed: %d", rc);
    return NULL;
  }

  sndio->src = g_unix_fd_source_new (sndio->pfd.fd, G_IO_IN);
  g_source_set_callback (sndio->src, G_SOURCE_FUNC(gst_mixer_sndio_src_callback), sndio, NULL);
  g_source_attach (sndio->src, g_main_context_default ());
  return GST_MIXER(sndio);
}

GList *gst_mixer_sndio_probe (GList *card_list)
{
  GstMixer *mixer = NULL;
  struct sioctl_hdl *hdl;
  char *devname = SIO_DEVANY;
  hdl = sioctl_open(devname, SIOCTL_READ | SIOCTL_WRITE, 0);
  if (hdl == NULL) {
    g_critical ("Failed to open device '%s'", devname);
    return NULL;
  }

  mixer = gst_mixer_sndio_new(hdl);

  if (mixer == NULL)
    return NULL;

  card_list = g_list_append (card_list, mixer);
  return card_list;
}

