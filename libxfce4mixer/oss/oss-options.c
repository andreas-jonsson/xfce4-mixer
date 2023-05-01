/*
 * Copyright (C) 2020  Ali Abdallah <ali.abdallah@suse.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your options) any later version.
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

#include "oss-options.h"
#include "gst-mixer.h"

struct _GstMixerOssOptions
{
  GstMixerOssTrack parent;
  GList *values;
};

G_DEFINE_TYPE (GstMixerOssOptions, gst_mixer_oss_options, GST_MIXER_TYPE_OSS_TRACK)

static void
gst_mixer_oss_options_finalize (GObject *self)
{
  /*GstMixerOssOptions *options = GST_MIXER_OSS_OPTIONS (self);*/

  G_OBJECT_CLASS (gst_mixer_oss_options_parent_class)->finalize (self);
}


static void
gst_mixer_oss_options_init (GstMixerOssOptions *mixer)
{

}


static void
gst_mixer_oss_options_class_init (GstMixerOssOptionsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = (void (*) (GObject *object)) gst_mixer_oss_options_finalize;
}


GstMixerOssOptions *gst_mixer_oss_options_new (void)
{
  GstMixerOssOptions *options = NULL;
  return options;
}

