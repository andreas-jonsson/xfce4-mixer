/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <string.h> /* memset() */

#include "xfce-mixer-prefbox.h"

#include "xfce-mixer-prefbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 1 "mixer-prefbox.gob"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#line 35 "xfce-mixer-prefbox.c"

#line 6 "mixer-prefbox.gob"

#include <gtk/gtk.h>
#include <libxfcegui4/libxfcegui4.h>
#include <libxfce4util/libxfce4util.h>
#include "xfce-mixer-preferences.h"
#include "vc.h"
#include "xfce-mixer-cache-vc.h"
#include "launcher-entry.h"

/* why is this deprecated when it is needed by combo ? O_o */
GtkWidget *gtk_list_item_new_with_label (const gchar *label);


#line 51 "xfce-mixer-prefbox.c"

#line 23 "mixer-prefbox.gob"

#include "string_option_menu.h"

#define FHELPERS1
#include "helpers.inc"

#include "stringlist.inc"


#line 63 "xfce-mixer-prefbox.c"
/* self casting macros */
#define SELF(x) XFCE_MIXER_PREFBOX(x)
#define SELF_CONST(x) XFCE_MIXER_PREFBOX_CONST(x)
#define IS_SELF(x) XFCE_IS_MIXER_PREFBOX(x)
#define TYPE_SELF XFCE_TYPE_MIXER_PREFBOX
#define SELF_CLASS(x) XFCE_MIXER_PREFBOX_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MIXER_PREFBOX_GET_CLASS(x)

/* self typedefs */
typedef XfceMixerPrefbox Self;
typedef XfceMixerPrefboxClass SelfClass;

/* here are local prototypes */
static void xfce_mixer_prefbox_class_init (XfceMixerPrefboxClass * c) G_GNUC_UNUSED;
static void ___real_xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self);
static void xfce_mixer_prefbox_init (XfceMixerPrefbox * self) G_GNUC_UNUSED;

/*
 * Signal connection wrapper macro shortcuts
 */
#define self_connect__device_changed(object,func,data)	xfce_mixer_prefbox_connect__device_changed((object),(func),(data))
#define self_connect_after__device_changed(object,func,data)	xfce_mixer_prefbox_connect_after__device_changed((object),(func),(data))
#define self_connect_data__device_changed(object,func,data,destroy_data,flags)	xfce_mixer_prefbox_connect_data__device_changed((object),(func),(data),(destroy_data),(flags))

enum {
	DEVICE_CHANGED_SIGNAL,
	LAST_SIGNAL
};

static guint object_signals[LAST_SIGNAL] = {0};

/* pointer to the class of our parent */
static GtkVBoxClass *parent_class = NULL;

/* Short form macros */
#define self_fill_defaults xfce_mixer_prefbox_fill_defaults
#define self_fill_device_list xfce_mixer_prefbox_fill_device_list
#define self_fill_master_list xfce_mixer_prefbox_fill_master_list
#define self_find_name_by_master_i xfce_mixer_prefbox_find_name_by_master_i
#define self_find_master_by_name xfce_mixer_prefbox_find_master_by_name
#define self_device_changed xfce_mixer_prefbox_device_changed
#define self_add_command_box xfce_mixer_prefbox_add_command_box
#define self_device_changed_delayed_cb xfce_mixer_prefbox_device_changed_delayed_cb
#define self_device_changed_cb xfce_mixer_prefbox_device_changed_cb
#define self_new xfce_mixer_prefbox_new
#define self_fill_preferences xfce_mixer_prefbox_fill_preferences
#define self_save_preferences xfce_mixer_prefbox_save_preferences
GType
xfce_mixer_prefbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMixerPrefboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mixer_prefbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMixerPrefbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mixer_prefbox_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_VBOX, "XfceMixerPrefbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMixerPrefbox *)g_object_new(xfce_mixer_prefbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMixerPrefbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMixerPrefbox *
GET_NEW_VARG (const char *first, ...)
{
	XfceMixerPrefbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMixerPrefbox *)g_object_new_valist (xfce_mixer_prefbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::finalize"
	XfceMixerPrefbox *self G_GNUC_UNUSED = XFCE_MIXER_PREFBOX (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#define master_lst (self->master_lst)
#define VAR master_lst
	{
#line 37 "mixer-prefbox.gob"
	
			stringlist_free(VAR);
			VAR = NULL;
		}
#line 171 "xfce-mixer-prefbox.c"
	memset(&master_lst, 0, sizeof(master_lst));
#undef VAR
#undef master_lst
#define device_entry_delayer (self->_priv->device_entry_delayer)
#define VAR device_entry_delayer
	{
#line 47 "mixer-prefbox.gob"
	 delayer_free (VAR); }
#line 180 "xfce-mixer-prefbox.c"
	memset(&device_entry_delayer, 0, sizeof(device_entry_delayer));
#undef VAR
#undef device_entry_delayer
}
#undef __GOB_FUNCTION__

static void 
xfce_mixer_prefbox_class_init (XfceMixerPrefboxClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(XfceMixerPrefboxPrivate));

	parent_class = g_type_class_ref (GTK_TYPE_VBOX);

	object_signals[DEVICE_CHANGED_SIGNAL] =
		g_signal_new ("device_changed",
			G_TYPE_FROM_CLASS (g_object_class),
			(GSignalFlags)(G_SIGNAL_RUN_FIRST | G_SIGNAL_ACTION),
			G_STRUCT_OFFSET (XfceMixerPrefboxClass, device_changed),
			NULL, NULL,
			g_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE, 0);

#line 135 "mixer-prefbox.gob"
	c->device_changed = ___real_xfce_mixer_prefbox_device_changed;
#line 208 "xfce-mixer-prefbox.c"
	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__
#line 166 "mixer-prefbox.gob"
static void 
xfce_mixer_prefbox_init (XfceMixerPrefbox * self G_GNUC_UNUSED)
#line 215 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,XFCE_TYPE_MIXER_PREFBOX,XfceMixerPrefboxPrivate);
#line 23 "mixer-prefbox.gob"
	self->master_lst = NULL;
#line 221 "xfce-mixer-prefbox.c"
#line 37 "mixer-prefbox.gob"
	self->_priv->device_entry_delayer = 0;
#line 224 "xfce-mixer-prefbox.c"
#line 47 "mixer-prefbox.gob"
	self->launcher_entry = NULL;
#line 227 "xfce-mixer-prefbox.c"
#line 47 "mixer-prefbox.gob"
	self->click_b = NULL;
#line 230 "xfce-mixer-prefbox.c"
 {
#line 167 "mixer-prefbox.gob"

		GtkWidget *dentry;
		GtkWidget *item;

		gtk_box_set_spacing (GTK_BOX (self), 5);
		self->device_cb = GTK_COMBO (gtk_combo_new ());
		self->master_om = GTK_OPTION_MENU (gtk_option_menu_new ());


		gtk_container_set_border_width (GTK_CONTAINER (self), 5);
		gtk_box_pack_start (GTK_BOX (self), twocol_label (_("Device:"), GTK_WIDGET (self->device_cb)), FALSE, FALSE, 0);
		gtk_box_pack_start (GTK_BOX (self), twocol_label (_("Wannabe Master:"), GTK_WIDGET (self->master_om)), FALSE, FALSE, 0);

		gtk_box_pack_start (GTK_BOX (self), headline (_("When clicked"), &self->click_b), FALSE, FALSE, 0);


		gtk_entry_set_max_length (GTK_ENTRY (self->device_cb->entry), 50);

		gtk_combo_set_value_in_list (GTK_COMBO (self->device_cb), FALSE, TRUE);
		if (self->execu_cb)
			gtk_combo_set_value_in_list (GTK_COMBO (self->execu_cb), FALSE, TRUE);

		self_fill_device_list (self);

		emit self_device_changed (self);

		dentry = GTK_WIDGET (self->device_cb->entry);
		g_signal_connect_swapped (G_OBJECT (dentry), "changed", G_CALLBACK (self_device_changed_cb), self);

		if (self->execu_cb && g_find_program_in_path ("xfce4-mixer")) {
			item = gtk_list_item_new_with_label ("xfce4-mixer");
			gtk_widget_show (item);
			gtk_combo_set_item_string (GTK_COMBO (self->execu_cb), GTK_ITEM (item), "xfce4-mixer");
			gtk_container_add (GTK_CONTAINER (GTK_COMBO (self->execu_cb)->list), item);
		}
	
#line 269 "xfce-mixer-prefbox.c"
 }
}
#undef __GOB_FUNCTION__


#line 51 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_defaults (XfceMixerPrefbox * self)
#line 278 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_defaults"
#line 51 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 51 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 285 "xfce-mixer-prefbox.c"
{
#line 52 "mixer-prefbox.gob"
	
		launcher_entry_set_command (self->launcher_entry, "xfce4-mixer", FALSE, TRUE);
		gtk_entry_set_text (GTK_ENTRY (self->device_cb->entry), "");
		emit self_device_changed (self);
	}}
#line 293 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 58 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_device_list (XfceMixerPrefbox * self)
#line 299 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_device_list"
#line 58 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 58 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 306 "xfce-mixer-prefbox.c"
{
#line 59 "mixer-prefbox.gob"
	
		GList *gl;

		gl = vc_get_device_list ();
		if (gl) {
			gtk_combo_set_popdown_strings (GTK_COMBO (self->device_cb), gl);
			vc_free_device_list (gl);
		} else {
			/* TODO: clear popdown list O_o */
			/* gtk_combo_set_popdown_strings (, NUL); issues warning */
		}
	}}
#line 321 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 72 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_master_list (XfceMixerPrefbox * self)
#line 327 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_master_list"
#line 72 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 72 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 334 "xfce-mixer-prefbox.c"
{
#line 73 "mixer-prefbox.gob"
	
		stringlist_free (self->master_lst);
		self->master_lst = NULL;
		xfce_mixer_cache_vc_foreach (master_enum_cb, &self->master_lst);

		fill_string_option_menu (self->master_om, self->master_lst);
	}}
#line 344 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 81 "mixer-prefbox.gob"
gchar * 
xfce_mixer_prefbox_find_name_by_master_i (XfceMixerPrefbox * self, gint master_i)
#line 350 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::find_name_by_master_i"
#line 81 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gchar * )0);
#line 81 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gchar * )0);
#line 357 "xfce-mixer-prefbox.c"
{
#line 82 "mixer-prefbox.gob"
	
		gint i;
		GList *g;
		gchar *s;

		if (master_i == -1)
			return NULL;

		i = 0;
		g = self->master_lst;
		while (g) {
			s = (gchar *)g->data;
			if (s) {
				if (i == master_i)
					return g_strdup (s);
			}

			g = g_list_next (g);
			++i;
		}
		return NULL;
	}}
#line 382 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 105 "mixer-prefbox.gob"
gint 
xfce_mixer_prefbox_find_master_by_name (XfceMixerPrefbox * self, gchar const * name)
#line 388 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::find_master_by_name"
#line 105 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gint )0);
#line 105 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gint )0);
#line 395 "xfce-mixer-prefbox.c"
{
#line 106 "mixer-prefbox.gob"
	
		gint i;
		gint master_i;
		GList *g;
		gchar *s;

		master_i = -1;
		if (!name) {
			return master_i;
		}

		i = 0;
		g = self->master_lst;

		while (g) {
			s = (gchar *)g->data;
			if (s) {
				if (g_str_equal (s, name))
					master_i = i;
			}

			g = g_list_next (g);
			++i;
		}

		return master_i;
	}}
#line 425 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 135 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self)
#line 431 "xfce-mixer-prefbox.c"
{
	GValue ___param_values[1];
	GValue ___return_val;

memset (&___return_val, 0, sizeof (___return_val));
memset (&___param_values, 0, sizeof (___param_values));

#line 135 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 135 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 443 "xfce-mixer-prefbox.c"

	___param_values[0].g_type = 0;
	g_value_init (&___param_values[0], G_TYPE_FROM_INSTANCE (self));
	g_value_set_instance (&___param_values[0], (gpointer) self);

	g_signal_emitv (___param_values,
		object_signals[DEVICE_CHANGED_SIGNAL],
		0 /* detail */,
		&___return_val);

	g_value_unset (&___param_values[0]);
}
#line 135 "mixer-prefbox.gob"
static void 
___real_xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self G_GNUC_UNUSED)
#line 459 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed"
{
#line 137 "mixer-prefbox.gob"
	
		gint omi;
		gchar const *txt;
		gchar *master;
		txt = gtk_entry_get_text (GTK_ENTRY (self->device_cb->entry));
		if (txt && txt[0]) {
			vc_set_device (txt);
		} else {
			vc_set_device (vc_get_device ());
		}

		omi = gtk_option_menu_get_history (self->master_om);
		master = self_find_name_by_master_i (self, omi);

		self_fill_master_list (self);
		omi = -1;
		if (master) {
			omi = self_find_master_by_name (self, master);
			g_free (master);
		}

		/*if (omi == -1)
			omi = self_find_master (self);
		*/

		gtk_option_menu_set_history (self->master_om, omi);

	}}
#line 492 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__


#line 204 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_add_command_box (XfceMixerPrefbox * self)
#line 499 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::add_command_box"
#line 204 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 204 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 506 "xfce-mixer-prefbox.c"
{
#line 205 "mixer-prefbox.gob"
	
		self->launcher_entry = launcher_entry_new ();
		self->execu_cb = NULL; /*self->ic->combo;*/
		/*self->execu_entry = self->ic->command_entry;*/
		/*self->startup_nf_c = GTK_CHECK_BUTTON (self->ic->sn_checkbutton);*/
		/*self->in_terminal_c = GTK_CHECK_BUTTON (self->ic->term_checkbutton);*/
		gtk_widget_show (GTK_WIDGET (launcher_entry_get_widget (self->launcher_entry)));
		gtk_box_pack_start (GTK_BOX (self->click_b), GTK_WIDGET (launcher_entry_get_widget (self->launcher_entry)), FALSE, FALSE, 0);
	}}
#line 518 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 215 "mixer-prefbox.gob"
gboolean 
xfce_mixer_prefbox_device_changed_delayed_cb (XfceMixerPrefbox * self)
#line 524 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed_delayed_cb"
#line 215 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 215 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gboolean )0);
#line 531 "xfce-mixer-prefbox.c"
{
#line 216 "mixer-prefbox.gob"
	
		/*printf ("delayed\n");*/
		emit self_device_changed (self);
		return FALSE;
	}}
#line 539 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 222 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_device_changed_cb (XfceMixerPrefbox * self, GtkEditable * e)
#line 545 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed_cb"
#line 222 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 222 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 552 "xfce-mixer-prefbox.c"
{
#line 223 "mixer-prefbox.gob"
	
		delayer_restart (
			&self->_priv->device_entry_delayer, 
			500, (GSourceFunc) (self_device_changed_delayed_cb), 
			self
		);
	}}
#line 562 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 231 "mixer-prefbox.gob"
XfceMixerPrefbox * 
xfce_mixer_prefbox_new (void)
#line 568 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::new"
{
#line 232 "mixer-prefbox.gob"
	
		XfceMixerPrefbox* w;
		w = (XfceMixerPrefbox*) (GET_NEW);
		xfce_mixer_prefbox_add_command_box (XFCE_MIXER_PREFBOX (w));
		return w;
	}}
#line 579 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 239 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_preferences (XfceMixerPrefbox * self, XfceMixerPreferences * p)
#line 585 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_preferences"
#line 239 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 239 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 592 "xfce-mixer-prefbox.c"
{
#line 240 "mixer-prefbox.gob"
	
		gint omi;
		gchar* launcher_command;
		gboolean launcher_run_in_terminal;
		gboolean launcher_use_startup_notification;
		gchar* device;
		gchar* master_control;

		launcher_command = NULL;
		launcher_run_in_terminal = FALSE;
		launcher_use_startup_notification = FALSE;
		device = NULL;
		master_control = NULL;

		if (!p) {
			self_fill_defaults (self);
			return;
		}

		g_object_get (G_OBJECT (p),
			"launcher_command", &launcher_command, 
			"launcher_run_in_terminal", &launcher_run_in_terminal,
			"launcher_use_startup_notification", &launcher_use_startup_notification,
			"device", &device,
			"master", &master_control,
			NULL
		);

		launcher_entry_set_command (self->launcher_entry, 
			nvl (launcher_command, "xfce4-mixer"),
			launcher_run_in_terminal,
			launcher_use_startup_notification
		);

		gtk_entry_set_text (GTK_ENTRY (self->device_cb->entry), nvl (device, ""));

		omi = self_find_master_by_name (self, master_control);

		gtk_option_menu_set_history (self->master_om, omi);

		if (master_control) {
			g_free (master_control);
			master_control = NULL;
		}

		if (device) {
			g_free (device);
			device = NULL;
		}

		if (launcher_command) {
			g_free (launcher_command);
			launcher_command = NULL;
		}

		emit self_device_changed (self);
	}}
#line 652 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 298 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_save_preferences (XfceMixerPrefbox * self, XfceMixerPreferences * p)
#line 658 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::save_preferences"
#line 298 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 298 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 665 "xfce-mixer-prefbox.c"
{
#line 299 "mixer-prefbox.gob"
	
		gint omi;
		gchar *execu;
		gchar const *device;
		gchar *master;
		gboolean startup_nf;
		gboolean in_terminal;

		if (!p)
			return;

		device = gtk_entry_get_text (GTK_ENTRY (self->device_cb->entry));
		emit self_device_changed (self);

		omi = gtk_option_menu_get_history (self->master_om);
		master = self_find_name_by_master_i (self, omi);

		launcher_entry_get_command (self->launcher_entry, &execu, &in_terminal, &startup_nf);

		g_object_set (G_OBJECT (p),
			"device", device,
			"launcher_command", execu,
			"master", master,
			"launcher_use_startup_notification", startup_nf,
			"launcher_run_in_terminal", in_terminal,
			NULL
		);

		if (execu)
			g_free (execu);

		if (master)
			g_free (master);
	}}
#line 702 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__
