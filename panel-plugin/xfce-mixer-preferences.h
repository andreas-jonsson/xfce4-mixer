/* Generated by GOB (v2.0.9)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MIXER_PREFERENCES_H__
#define __XFCE_MIXER_PREFERENCES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>



#include "helpers_h.inc"



#include "xfce-mixer-pxml.h"


/*
 * Type checking and casting macros
 */
#define XFCE_TYPE_MIXER_PREFERENCES	(xfce_mixer_preferences_get_type())
#define XFCE_MIXER_PREFERENCES(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_preferences_get_type(), XfceMixerPreferences)
#define XFCE_MIXER_PREFERENCES_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_preferences_get_type(), XfceMixerPreferences const)
#define XFCE_MIXER_PREFERENCES_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), xfce_mixer_preferences_get_type(), XfceMixerPreferencesClass)
#define XFCE_IS_MIXER_PREFERENCES(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), xfce_mixer_preferences_get_type ())

#define XFCE_MIXER_PREFERENCES_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), xfce_mixer_preferences_get_type(), XfceMixerPreferencesClass)

/* Private structure type */
typedef struct _XfceMixerPreferencesPrivate XfceMixerPreferencesPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_XFCE_MIXER_PREFERENCES__
#define __TYPEDEF_XFCE_MIXER_PREFERENCES__
typedef struct _XfceMixerPreferences XfceMixerPreferences;
#endif
struct _XfceMixerPreferences {
	GObject __parent__;
	/*< public >*/
	gchar * device;
	gchar * execu;
	gboolean in_terminal;
	gboolean startup_nf;
	/*< private >*/
	gchar * probably_master; /* protected */
	GList * master_lst; /* protected */
	XfceMixerPxml * xml; /* protected */
	XfceMixerPreferencesPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _XfceMixerPreferencesClass XfceMixerPreferencesClass;
struct _XfceMixerPreferencesClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	xfce_mixer_preferences_get_type	(void);
XfceMixerPreferences * 	xfce_mixer_preferences_new	(void);
void 	xfce_mixer_preferences_load	(XfceMixerPreferences * self,
					xmlNodePtr parent);
void 	xfce_mixer_preferences_save	(XfceMixerPreferences * self,
					xmlNodePtr parent);

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define XFCE_MIXER_PREFERENCES_PROP_DEVICE(arg)    	"device", __extension__ ({gchar *z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_GET_PROP_DEVICE(arg)	"device", __extension__ ({gchar **z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_PROP_MASTER(arg)    	"master", __extension__ ({gchar *z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_GET_PROP_MASTER(arg)	"master", __extension__ ({gchar **z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_PROP_EXECU(arg)    	"execu", __extension__ ({gchar *z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_GET_PROP_EXECU(arg)	"execu", __extension__ ({gchar **z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_PROP_IN_TERMINAL(arg)    	"in_terminal", __extension__ ({gboolean z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_GET_PROP_IN_TERMINAL(arg)	"in_terminal", __extension__ ({gboolean *z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_PROP_STARTUP_NF(arg)    	"startup_nf", __extension__ ({gboolean z = (arg); z;})
#define XFCE_MIXER_PREFERENCES_GET_PROP_STARTUP_NF(arg)	"startup_nf", __extension__ ({gboolean *z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define XFCE_MIXER_PREFERENCES_PROP_DEVICE(arg)    	"device",(gchar *)(arg)
#define XFCE_MIXER_PREFERENCES_GET_PROP_DEVICE(arg)	"device",(gchar **)(arg)
#define XFCE_MIXER_PREFERENCES_PROP_MASTER(arg)    	"master",(gchar *)(arg)
#define XFCE_MIXER_PREFERENCES_GET_PROP_MASTER(arg)	"master",(gchar **)(arg)
#define XFCE_MIXER_PREFERENCES_PROP_EXECU(arg)    	"execu",(gchar *)(arg)
#define XFCE_MIXER_PREFERENCES_GET_PROP_EXECU(arg)	"execu",(gchar **)(arg)
#define XFCE_MIXER_PREFERENCES_PROP_IN_TERMINAL(arg)    	"in_terminal",(gboolean )(arg)
#define XFCE_MIXER_PREFERENCES_GET_PROP_IN_TERMINAL(arg)	"in_terminal",(gboolean *)(arg)
#define XFCE_MIXER_PREFERENCES_PROP_STARTUP_NF(arg)    	"startup_nf",(gboolean )(arg)
#define XFCE_MIXER_PREFERENCES_GET_PROP_STARTUP_NF(arg)	"startup_nf",(gboolean *)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
