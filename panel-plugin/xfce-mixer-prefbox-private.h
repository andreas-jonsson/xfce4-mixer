/* Generated by GOB (v2.0.6)   (do not edit directly) */

#ifndef __XFCE_MIXER_PREFBOX_PRIVATE_H__
#define __XFCE_MIXER_PREFBOX_PRIVATE_H__

#include "xfce-mixer-prefbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include <libxfcegui4/xfce_framebox.h>
#include <libxfce4util/i18n.h>
#include "xfce-mixer-preferences.h"
#include "vc.h"
#include "xfce-mixer-cache-vc.h"
#include "xfce-mixer-pxml.h"
#include <panel/item_dialog.h>
#include <panel/plugins.h>

/* why is this deprecated when it is needed by combo ? O_o */
GtkWidget *gtk_list_item_new_with_label (const gchar *label);


#line 6 "mixer-prefbox.gob"
#line 30 "xfce-mixer-prefbox-private.h"
struct _XfceMixerPrefboxPrivate {
#line 45 "mixer-prefbox.gob"
	delayer_t device_entry_delayer;
#line 34 "xfce-mixer-prefbox-private.h"
};
void 	xfce_mixer_prefbox_fill_device_list	(XfceMixerPrefbox * self);
void 	xfce_mixer_prefbox_fill_master_list	(XfceMixerPrefbox * self);
gchar * 	xfce_mixer_prefbox_find_name_by_master_i	(XfceMixerPrefbox * self, gint master_i);
gint 	xfce_mixer_prefbox_find_master_by_name	(XfceMixerPrefbox * self, gchar const * name);
void 	xfce_mixer_prefbox_add_command_box	(XfceMixerPrefbox * self, Control * plugin);
gboolean 	xfce_mixer_prefbox_device_changed_delayed_cb	(XfceMixerPrefbox * self);
void 	xfce_mixer_prefbox_device_changed_cb	(XfceMixerPrefbox * self, GtkEditable * e);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif