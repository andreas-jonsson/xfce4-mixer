/* Generated by GOB (v2.0.6) on Fri Jan  9 00:16:54 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 6

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "xfce-mixer-mcs-client.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 1 "mixer-mcs-client.gob"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#line 31 "xfce-mixer-mcs-client.c"

#line 6 "mixer-mcs-client.gob"

#include <gtk/gtk.h>
#include <libxfce4mcs/mcs-client.h>

#line 38 "xfce-mixer-mcs-client.c"

#line 10 "mixer-mcs-client.gob"

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <gdk/gdkx.h>
#include <libxfce4util/i18n.h>
#include "mixer-mcs-names.h"
#define emit

/* event handling */
static void
notify_cb (const char *name, const char *channel_name,
	   McsAction action, McsSetting * setting, void *data)
{
	XfceMixerMcsClient *m;
	m = XFCE_MIXER_MCS_CLIENT (data);

	if (!m->channel)
		return;

	if (g_ascii_strcasecmp (m->channel, channel_name))
		return;

    switch (action)
    {
	case MCS_ACTION_NEW:
	    /* fall through */
	case MCS_ACTION_CHANGED:
		xfce_mixer_mcs_client_update_setting (m, name, setting);
	    break;
	case MCS_ACTION_DELETED:
	    /* We don't use this now. Perhaps revert to default? */
	    break;
    }
}

static GdkFilterReturn
client_event_filter (GdkXEvent * xevent, GdkEvent * event, gpointer data)
{
	XfceMixerMcsClient *m;
	m = XFCE_MIXER_MCS_CLIENT (data);

	if (mcs_client_process_event (m->client, (XEvent *) xevent))
		return GDK_FILTER_REMOVE;
	else
		return GDK_FILTER_CONTINUE;
}

static void
watch_cb (Window window, Bool is_start, long mask, void *cb_data)
{
    GdkWindow *gdkwin;

    gdkwin = gdk_window_lookup (window);

    if (is_start)
	gdk_window_add_filter (gdkwin, client_event_filter, cb_data);
    else
	gdk_window_remove_filter (gdkwin, client_event_filter, cb_data);
}


#line 102 "xfce-mixer-mcs-client.c"
/* self casting macros */
#define SELF(x) XFCE_MIXER_MCS_CLIENT(x)
#define SELF_CONST(x) XFCE_MIXER_MCS_CLIENT_CONST(x)
#define IS_SELF(x) XFCE_IS_MIXER_MCS_CLIENT(x)
#define TYPE_SELF XFCE_TYPE_MIXER_MCS_CLIENT
#define SELF_CLASS(x) XFCE_MIXER_MCS_CLIENT_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MIXER_MCS_CLIENT_GET_CLASS(x)

/* self typedefs */
typedef XfceMixerMcsClient Self;
typedef XfceMixerMcsClientClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void xfce_mixer_mcs_client_class_init (XfceMixerMcsClientClass * c) G_GNUC_UNUSED;
static void ___real_xfce_mixer_mcs_client_changed (XfceMixerMcsClient * self);
static void xfce_mixer_mcs_client_init (XfceMixerMcsClient * self) G_GNUC_UNUSED;

/*
 * Signal connection wrapper macro shortcuts
 */
#define self_connect__changed(object,func,data)	xfce_mixer_mcs_client_connect__changed((object),(func),(data))
#define self_connect_after__changed(object,func,data)	xfce_mixer_mcs_client_connect_after__changed((object),(func),(data))
#define self_connect_data__changed(object,func,data,destroy_data,flags)	xfce_mixer_mcs_client_connect_data__changed((object),(func),(data),(destroy_data),(flags))

enum {
	CHANGED_SIGNAL,
	LAST_SIGNAL
};

enum {
	PROP_0,
	PROP_CHANNEL
};

static guint object_signals[LAST_SIGNAL] = {0};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define self_changed(args...) xfce_mixer_mcs_client_changed(args)
#define self_update_setting(args...) xfce_mixer_mcs_client_update_setting(args)
#define self_get_setting(args...) xfce_mixer_mcs_client_get_setting(args)
#define self_get_useful_controls(args...) xfce_mixer_mcs_client_get_useful_controls(args)
#define self_new() xfce_mixer_mcs_client_new()
#endif /* __GNUC__ && !__STRICT_ANSI__ */

/* Short form pointers */
static void (* const self_changed) (XfceMixerMcsClient * self) = xfce_mixer_mcs_client_changed;
static void (* const self_update_setting) (XfceMixerMcsClient * self, gchar const * name, McsSetting * setting) = xfce_mixer_mcs_client_update_setting;
static gchar * (* const self_get_setting) (XfceMixerMcsClient * self, gchar const * name) = xfce_mixer_mcs_client_get_setting;
static gchar * (* const self_get_useful_controls) (XfceMixerMcsClient * self, gchar const * device) = xfce_mixer_mcs_client_get_useful_controls;
static XfceMixerMcsClient * (* const self_new) (void) = xfce_mixer_mcs_client_new;

GType
xfce_mixer_mcs_client_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMixerMcsClientClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mixer_mcs_client_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMixerMcsClient),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mixer_mcs_client_init,
		};

		type = g_type_register_static (G_TYPE_OBJECT, "XfceMixerMcsClient", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMixerMcsClient *)g_object_new(xfce_mixer_mcs_client_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMixerMcsClient * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMixerMcsClient *
GET_NEW_VARG (const char *first, ...)
{
	XfceMixerMcsClient *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMixerMcsClient *)g_object_new_valist (xfce_mixer_mcs_client_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::finalize"
	XfceMixerMcsClient *self = XFCE_MIXER_MCS_CLIENT (obj_self);
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 74 "mixer-mcs-client.gob"
	if(self->channel) { ((*(void (*)(void *))g_free)) (self->channel); self->channel = NULL; }
#line 212 "xfce-mixer-mcs-client.c"
#line 77 "mixer-mcs-client.gob"
	if(self->client) { ((*(void (*)(void *))mcs_client_destroy)) (self->client); self->client = NULL; }
#line 215 "xfce-mixer-mcs-client.c"
#line 79 "mixer-mcs-client.gob"
	if(self->hash) { ((*(void (*)(void *))g_hash_table_destroy)) (self->hash); self->hash = NULL; }
#line 218 "xfce-mixer-mcs-client.c"
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__

static void 
xfce_mixer_mcs_client_class_init (XfceMixerMcsClientClass * c)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::class_init"
	GObjectClass *g_object_class = (GObjectClass*) c;

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

	object_signals[CHANGED_SIGNAL] =
		g_signal_new ("changed",
			G_TYPE_FROM_CLASS (g_object_class),
			(GSignalFlags)(G_SIGNAL_RUN_FIRST | G_SIGNAL_ACTION),
			G_STRUCT_OFFSET (XfceMixerMcsClientClass, changed),
			NULL, NULL,
			g_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE, 0);

#line 96 "mixer-mcs-client.gob"
	c->changed = ___real_xfce_mixer_mcs_client_changed;
#line 243 "xfce-mixer-mcs-client.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_string
		("channel" /* name */,
		 "The mcs channel to use" /* nick */,
		 "The mcs channel to use" /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_CHANNEL,
		param_spec);
    }
	return;
	c = NULL;
	g_object_class = NULL;
}
#undef __GOB_FUNCTION__
#line 102 "mixer-mcs-client.gob"
static void 
xfce_mixer_mcs_client_init (XfceMixerMcsClient * self)
#line 268 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::init"
#line 10 "mixer-mcs-client.gob"
	self->channel = NULL;
#line 273 "xfce-mixer-mcs-client.c"
#line 10 "mixer-mcs-client.gob"
	self->client = NULL;
#line 276 "xfce-mixer-mcs-client.c"
#line 10 "mixer-mcs-client.gob"
	self->hash = NULL;
#line 279 "xfce-mixer-mcs-client.c"
 {
#line 103 "mixer-mcs-client.gob"

		Display *dpy = GDK_DISPLAY ();
		int screen = DefaultScreen (dpy);

		self->client = NULL;

		if (!mcs_client_check_manager (dpy, screen, "xfce-mcs-manager"))
			g_warning ("MCS settings manager not running!");
		else
			self->client = mcs_client_new (dpy, screen, notify_cb, watch_cb, self);

		self->hash = g_hash_table_new (g_str_hash, g_str_equal);
	
#line 295 "xfce-mixer-mcs-client.c"
 }
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL,
	GParamSpec *pspec)
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::set_property"
{
	XfceMixerMcsClient *self;

	self = XFCE_MIXER_MCS_CLIENT (object);

	switch (property_id) {
	case PROP_CHANNEL:
		{
#line 87 "mixer-mcs-client.gob"

		if (self->channel) {
			g_free (self->channel);
			self->channel = NULL;
		}
		self->channel = g_strdup (g_value_get_string (VAL));
		mcs_client_add_channel (self->client, self->channel);
	
#line 325 "xfce-mixer-mcs-client.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
	return;
	self = NULL;
	VAL = NULL;
	pspec = NULL;
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL,
	GParamSpec *pspec)
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::get_property"
{
	XfceMixerMcsClient *self;

	self = XFCE_MIXER_MCS_CLIENT (object);

	switch (property_id) {
	case PROP_CHANNEL:
		{
#line 84 "mixer-mcs-client.gob"

		g_value_set_string (VAL, self->channel);
	
#line 362 "xfce-mixer-mcs-client.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
	return;
	self = NULL;
	VAL = NULL;
	pspec = NULL;
}
#undef __GOB_FUNCTION__


#line 96 "mixer-mcs-client.gob"
void 
xfce_mixer_mcs_client_changed (XfceMixerMcsClient * self)
#line 385 "xfce-mixer-mcs-client.c"
{
	GValue ___param_values[1];
	GValue ___return_val = {0};

#line 96 "mixer-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 96 "mixer-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MIXER_MCS_CLIENT (self));
#line 394 "xfce-mixer-mcs-client.c"

	___param_values[0].g_type = 0;
	g_value_init (&___param_values[0], G_TYPE_FROM_INSTANCE (self));
	g_value_set_instance (&___param_values[0], (gpointer) self);

	g_signal_emitv (___param_values,
		object_signals[CHANGED_SIGNAL],
		0 /* detail */,
		&___return_val);

	g_value_unset (&___param_values[0]);
}
#line 96 "mixer-mcs-client.gob"
static void 
___real_xfce_mixer_mcs_client_changed (XfceMixerMcsClient * self)
#line 410 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::changed"
{
#line 98 "mixer-mcs-client.gob"
	
		/*g_warning ("changed");*/
	}}
#line 418 "xfce-mixer-mcs-client.c"
#undef __GOB_FUNCTION__


#line 117 "mixer-mcs-client.gob"
void 
xfce_mixer_mcs_client_update_setting (XfceMixerMcsClient * self, gchar const * name, McsSetting * setting)
#line 425 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::update_setting"
#line 117 "mixer-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 117 "mixer-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MIXER_MCS_CLIENT (self));
#line 432 "xfce-mixer-mcs-client.c"
{
#line 118 "mixer-mcs-client.gob"
	
		if (setting->type == MCS_TYPE_STRING) {
			g_hash_table_insert (self->hash, (gpointer)name, 
				(gpointer)setting->data.v_string);
		}
		emit self_changed (self);
	}}
#line 442 "xfce-mixer-mcs-client.c"
#undef __GOB_FUNCTION__

#line 126 "mixer-mcs-client.gob"
gchar * 
xfce_mixer_mcs_client_get_setting (XfceMixerMcsClient * self, gchar const * name)
#line 448 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::get_setting"
#line 126 "mixer-mcs-client.gob"
	g_return_val_if_fail (self != NULL, (gchar * )0);
#line 126 "mixer-mcs-client.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_MCS_CLIENT (self), (gchar * )0);
#line 455 "xfce-mixer-mcs-client.c"
{
#line 127 "mixer-mcs-client.gob"
	
		gchar *s;
		McsSetting *setting;
		s = g_hash_table_lookup (self->hash, name);
		if (!s) {
			setting = NULL;
			mcs_client_get_setting (self->client, name, self->channel, &setting); /* return val ? */

			if (setting && setting->type == MCS_TYPE_STRING && setting->data.v_string) {
				return g_strdup (setting->data.v_string);
			}

			return NULL;
		}

		return g_strdup (s);
	}}
#line 475 "xfce-mixer-mcs-client.c"
#undef __GOB_FUNCTION__

#line 145 "mixer-mcs-client.gob"
gchar * 
xfce_mixer_mcs_client_get_useful_controls (XfceMixerMcsClient * self, gchar const * device)
#line 481 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::get_useful_controls"
#line 145 "mixer-mcs-client.gob"
	g_return_val_if_fail (self != NULL, (gchar * )0);
#line 145 "mixer-mcs-client.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_MCS_CLIENT (self), (gchar * )0);
#line 488 "xfce-mixer-mcs-client.c"
{
#line 146 "mixer-mcs-client.gob"
	
		gchar *n;
		gchar *s;
		if (!device)
			return NULL;

		n = g_strdup_printf (MIXER_USEFUL_FMT, device);
		s = self_get_setting (self, n);
		g_free (n);
		return s;
	}}
#line 502 "xfce-mixer-mcs-client.c"
#undef __GOB_FUNCTION__

#line 158 "mixer-mcs-client.gob"
XfceMixerMcsClient * 
xfce_mixer_mcs_client_new (void)
#line 508 "xfce-mixer-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Mcs:Client::new"
{
#line 159 "mixer-mcs-client.gob"
	
		return XFCE_MIXER_MCS_CLIENT (GET_NEW);
	}}
#line 516 "xfce-mixer-mcs-client.c"
#undef __GOB_FUNCTION__


#if (!defined __GNUC__) || (defined __GNUC__ && defined __STRICT_ANSI__)
/*REALLY BAD HACK
  This is to avoid unused warnings if you don't call
  some method.  I need to find a better way to do
  this, not needed in GCC since we use some gcc
  extentions to make saner, faster code */
static void
___xfce_mixer_mcs_client_really_bad_hack_to_avoid_warnings(void)
{
	((void (*)(void))GET_NEW_VARG)();
	((void (*)(void))self_changed)();
	((void (*)(void))self_update_setting)();
	((void (*)(void))self_get_setting)();
	((void (*)(void))self_get_useful_controls)();
	((void (*)(void))self_new)();
	___xfce_mixer_mcs_client_really_bad_hack_to_avoid_warnings();
}
#endif /* !__GNUC__ || (__GNUC__ && __STRICT_ANSI__) */

