/* Generated by GOB (v2.0.6) on Sat Jan  3 20:02:13 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 6

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "xfce-mixer-view.h"

#include "xfce-mixer-view-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 2 "mixer-view.gob"

#define emit
#define SWITCH_ROWS 4
#define SWITCH_COLUMNS 3
#define SLIDER_HEIGHT 190

#define TRACEY printf

gboolean idle_cb (gpointer data)
{       
	GtkWindow *win = GTK_WINDOW (data);
	gtk_window_resize (GTK_WINDOW (win), 1, 1);

	return FALSE;   
}


#line 45 "xfce-mixer-view.c"

#line 20 "mixer-view.gob"

#include <gtk/gtk.h>
#include "xfce-mixer-control.h"
#include "xfce-mixer-control-factory.h"
#include "xfce-mixer-profile.h"
#include "disclosure-widget.h"


#line 56 "xfce-mixer-view.c"

#line 29 "mixer-view.gob"

static void control_list_free(GList *go)
{
	XfceMixerControl *c;
	GList *g;
	if (go) {
		g = g_list_last (go);

		while (g) {
			if (g->data) {
				c = XFCE_MIXER_CONTROL (g->data);
				gtk_widget_destroy (GTK_WIDGET (c));
				g_object_unref (G_OBJECT (c));
			}
			g = g_list_previous (g);
		}

		g_list_free (go);
	}
}


#line 81 "xfce-mixer-view.c"
/* self casting macros */
#define SELF(x) XFCE_MIXER_VIEW(x)
#define SELF_CONST(x) XFCE_MIXER_VIEW_CONST(x)
#define IS_SELF(x) XFCE_IS_MIXER_VIEW(x)
#define TYPE_SELF XFCE_TYPE_MIXER_VIEW
#define SELF_CLASS(x) XFCE_MIXER_VIEW_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MIXER_VIEW_GET_CLASS(x)

/* self typedefs */
typedef XfceMixerView Self;
typedef XfceMixerViewClass SelfClass;

/* here are local prototypes */
static void xfce_mixer_view_class_init (XfceMixerViewClass * c) G_GNUC_UNUSED;
static void xfce_mixer_view_toggled_cb (XfceMixerView * self, gpointer user_data) G_GNUC_UNUSED;
static void ___real_xfce_mixer_view_init_containers (XfceMixerView * self);
static void xfce_mixer_view_init (XfceMixerView * self) G_GNUC_UNUSED;
static void ___real_xfce_mixer_view_view_item_updated (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p);
static void ___real_xfce_mixer_view_view_cleared (XfceMixerView * self);
static void ___real_xfce_mixer_view_profile_cleared (XfceMixerView * self);
static void ___real_xfce_mixer_view_profile_item_updated (XfceMixerView * self, t_mixer_profile_item * p);

/* pointer to the class of our parent */
static GtkVBoxClass *parent_class = NULL;

/* Short form macros */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define self_add_control(args...) xfce_mixer_view_add_control(args)
#define self_del_control(args...) xfce_mixer_view_del_control(args)
#define self_new() xfce_mixer_view_new()
#define self_clear_controls(args...) xfce_mixer_view_clear_controls(args)
#define self_toggled_cb(args...) xfce_mixer_view_toggled_cb(args)
#define self_init_containers(args...) xfce_mixer_view_init_containers(args)
#define self_find_container(args...) xfce_mixer_view_find_container(args)
#define self_pack_control(args...) xfce_mixer_view_pack_control(args)
#define self_set_profile(args...) xfce_mixer_view_set_profile(args)
#define self_get_profile(args...) xfce_mixer_view_get_profile(args)
#define self_view_item_updated(args...) xfce_mixer_view_view_item_updated(args)
#define self_view_cleared(args...) xfce_mixer_view_view_cleared(args)
#define self_profile_cleared(args...) xfce_mixer_view_profile_cleared(args)
#define self_profile_item_updated(args...) xfce_mixer_view_profile_item_updated(args)
#endif /* __GNUC__ && !__STRICT_ANSI__ */

/* Short form pointers */
static XfceMixerControl * (* const self_add_control) (XfceMixerView * self, XfceMixerControl * c) = xfce_mixer_view_add_control;
static void (* const self_del_control) (XfceMixerView * self, XfceMixerControl * c) = xfce_mixer_view_del_control;
static XfceMixerView * (* const self_new) (void) = xfce_mixer_view_new;
static void (* const self_clear_controls) (XfceMixerView * self) = xfce_mixer_view_clear_controls;
static void (* const self_toggled_cb) (XfceMixerView * self, gpointer user_data) = xfce_mixer_view_toggled_cb;
static void (* const self_init_containers) (XfceMixerView * self) = xfce_mixer_view_init_containers;
static GtkContainer * (* const self_find_container) (XfceMixerView * self, gchar const * name) = xfce_mixer_view_find_container;
static void (* const self_pack_control) (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p) = xfce_mixer_view_pack_control;
static void (* const self_set_profile) (XfceMixerView * self, XfceMixerProfile * p) = xfce_mixer_view_set_profile;
static XfceMixerProfile const * (* const self_get_profile) (XfceMixerView * self) = xfce_mixer_view_get_profile;
static void (* const self_view_item_updated) (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p) = xfce_mixer_view_view_item_updated;
static void (* const self_view_cleared) (XfceMixerView * self) = xfce_mixer_view_view_cleared;
static void (* const self_profile_cleared) (XfceMixerView * self) = xfce_mixer_view_profile_cleared;
static void (* const self_profile_item_updated) (XfceMixerView * self, t_mixer_profile_item * p) = xfce_mixer_view_profile_item_updated;

GType
xfce_mixer_view_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMixerViewClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mixer_view_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMixerView),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mixer_view_init,
		};

		type = g_type_register_static (GTK_TYPE_VBOX, "XfceMixerView", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMixerView *)g_object_new(xfce_mixer_view_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMixerView * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMixerView *
GET_NEW_VARG (const char *first, ...)
{
	XfceMixerView *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMixerView *)g_object_new_valist (xfce_mixer_view_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::finalize"
	XfceMixerView *self = XFCE_MIXER_VIEW (obj_self);
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 61 "mixer-view.gob"
	if(self->controls) { ((*(void (*)(void *))control_list_free)) (self->controls); self->controls = NULL; }
#line 193 "xfce-mixer-view.c"
#define profile (self->profile)
#define VAR profile
	{
#line 65 "mixer-view.gob"
	
			self_set_profile (self, NULL);
		}
#line 201 "xfce-mixer-view.c"
	memset(&profile, 0, sizeof(profile));
#undef VAR
#undef profile
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__

static void 
xfce_mixer_view_class_init (XfceMixerViewClass * c)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::class_init"
	GObjectClass *g_object_class = (GObjectClass*) c;

	parent_class = g_type_class_ref (GTK_TYPE_VBOX);

#line 112 "mixer-view.gob"
	c->init_containers = ___real_xfce_mixer_view_init_containers;
#line 245 "mixer-view.gob"
	c->view_item_updated = ___real_xfce_mixer_view_view_item_updated;
#line 278 "mixer-view.gob"
	c->view_cleared = ___real_xfce_mixer_view_view_cleared;
#line 283 "mixer-view.gob"
	c->profile_cleared = ___real_xfce_mixer_view_profile_cleared;
#line 288 "mixer-view.gob"
	c->profile_item_updated = ___real_xfce_mixer_view_profile_item_updated;
#line 228 "xfce-mixer-view.c"
	g_object_class->finalize = ___finalize;
	return;
	c = NULL;
	g_object_class = NULL;
}
#undef __GOB_FUNCTION__
#line 160 "mixer-view.gob"
static void 
xfce_mixer_view_init (XfceMixerView * self)
#line 238 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::init"
#line 29 "mixer-view.gob"
	self->switches_r = 0;
#line 243 "xfce-mixer-view.c"
#line 29 "mixer-view.gob"
	self->switches_c = 0;
#line 246 "xfce-mixer-view.c"
#line 29 "mixer-view.gob"
	self->controls = NULL;
#line 249 "xfce-mixer-view.c"
#line 29 "mixer-view.gob"
	self->profile = NULL;
#line 252 "xfce-mixer-view.c"
 {
#line 160 "mixer-view.gob"

		self->kind = K_NORMAL;

		self_init_containers (self);
	
#line 260 "xfce-mixer-view.c"
 }
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__


#line 69 "mixer-view.gob"
XfceMixerControl * 
xfce_mixer_view_add_control (XfceMixerView * self, XfceMixerControl * c)
#line 271 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::add_control"
#line 69 "mixer-view.gob"
	g_return_val_if_fail (self != NULL, (XfceMixerControl * )0);
#line 69 "mixer-view.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_VIEW (self), (XfceMixerControl * )0);
#line 278 "xfce-mixer-view.c"
{
#line 70 "mixer-view.gob"
	
		g_object_ref (G_OBJECT (c));
		gtk_object_sink (GTK_OBJECT (c));
		self->controls = g_list_append (self->controls, c);
		return c;
	}}
#line 287 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 77 "mixer-view.gob"
void 
xfce_mixer_view_del_control (XfceMixerView * self, XfceMixerControl * c)
#line 293 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::del_control"
#line 77 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 77 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 300 "xfce-mixer-view.c"
{
#line 78 "mixer-view.gob"
	
		if (g_list_index (self->controls, c) > -1) {
			self->controls = g_list_remove (self->controls, c);
			gtk_widget_destroy (GTK_WIDGET (c));
			g_object_unref (c);
		}
	}}
#line 310 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 86 "mixer-view.gob"
XfceMixerView * 
xfce_mixer_view_new (void)
#line 316 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::new"
{
#line 87 "mixer-view.gob"
	
		return XFCE_MIXER_VIEW (GET_NEW);
	}}
#line 324 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 91 "mixer-view.gob"
void 
xfce_mixer_view_clear_controls (XfceMixerView * self)
#line 330 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::clear_controls"
#line 91 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 91 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 337 "xfce-mixer-view.c"
{
#line 92 "mixer-view.gob"
	
		control_list_free (self->controls);
		self->controls = NULL;
	}}
#line 344 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 97 "mixer-view.gob"
static void 
xfce_mixer_view_toggled_cb (XfceMixerView * self, gpointer user_data)
#line 350 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::toggled_cb"
#line 97 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 97 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 357 "xfce-mixer-view.c"
{
#line 98 "mixer-view.gob"
	 /* this function is a bit hacky, its for shrinking the window 
             after the disclosure widget was closed 
	  */ 
		GtkWidget *win;
		gboolean b;
        
		b = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (user_data));

		if (!b) {
			win = gtk_widget_get_toplevel (GTK_WIDGET (user_data));
			g_timeout_add (250 /*500*/, idle_cb, win);
		}
	}}
#line 373 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 112 "mixer-view.gob"
void 
xfce_mixer_view_init_containers (XfceMixerView * self)
#line 379 "xfce-mixer-view.c"
{
	XfceMixerViewClass *klass;
#line 112 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 112 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 386 "xfce-mixer-view.c"
	klass = XFCE_MIXER_VIEW_GET_CLASS(self);

	if(klass->init_containers)
		(*klass->init_containers)(self);
}
#line 112 "mixer-view.gob"
static void 
___real_xfce_mixer_view_init_containers (XfceMixerView * self)
#line 395 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::init_containers"
{
#line 113 "mixer-view.gob"
	
		self->vbox = GTK_BOX (gtk_vbox_new (FALSE, 5));
		gtk_widget_show (GTK_WIDGET (self->vbox));
		self->sliders = GTK_BOX (gtk_hbox_new (FALSE, 5));
		gtk_widget_set_size_request (GTK_WIDGET (self->sliders), -1, SLIDER_HEIGHT);

		self->swsliders = gtk_scrolled_window_new (NULL, NULL);
		gtk_scrolled_window_set_policy (
			GTK_SCROLLED_WINDOW (self->swsliders), 
			GTK_POLICY_AUTOMATIC, GTK_POLICY_NEVER
		);
		gtk_scrolled_window_add_with_viewport (
			GTK_SCROLLED_WINDOW (self->swsliders),
			GTK_WIDGET (self->sliders)
		);
		gtk_widget_show (self->swsliders);

		gtk_widget_show (GTK_WIDGET (self->sliders));
		self->switches = GTK_TABLE (gtk_table_new (SWITCH_ROWS, SWITCH_COLUMNS, FALSE));
/*		gtk_widget_show (GTK_WIDGET (self->switches));*/

		self->disclosure = cddb_disclosure_new (
			"Show Switches",
			"Hide Switches"
		);

		g_signal_connect_swapped (
			G_OBJECT (self->disclosure), 
			"toggled", G_CALLBACK (self_toggled_cb), self
		);

		/*self->disclosure = gtk_vbox_new (FALSE, 0);*/ /* todo */
		gtk_widget_show (GTK_WIDGET (self->disclosure));
		cddb_disclosure_set_container (CDDB_DISCLOSURE (self->disclosure), GTK_WIDGET (self->switches));

		gtk_box_pack_start (self->vbox, GTK_WIDGET (self->swsliders), TRUE, TRUE, 0);
		gtk_box_pack_start (self->vbox, GTK_WIDGET (self->disclosure), FALSE, FALSE, 0);
		gtk_box_pack_start (self->vbox, GTK_WIDGET (self->switches), TRUE, TRUE, 0);

		/*gtk_container_add (GTK_CONTAINER (self), GTK_WIDGET (self->vbox));*/
		gtk_box_pack_start (GTK_BOX (self), GTK_WIDGET (self->vbox), TRUE, TRUE, 0);

		gtk_widget_set_name (GTK_WIDGET (self->sliders), "sliders");
		gtk_widget_set_name (GTK_WIDGET (self->switches), "switches");

	}}
#line 446 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__


#line 166 "mixer-view.gob"
GtkContainer * 
xfce_mixer_view_find_container (XfceMixerView * self, gchar const * name)
#line 453 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::find_container"
#line 166 "mixer-view.gob"
	g_return_val_if_fail (self != NULL, (GtkContainer * )0);
#line 166 "mixer-view.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_VIEW (self), (GtkContainer * )0);
#line 460 "xfce-mixer-view.c"
{
#line 167 "mixer-view.gob"
	
		if (name) {
			if (g_str_equal (name, "sliders")) return GTK_CONTAINER (self->sliders);
			else if (g_str_equal (name, "switches")) return GTK_CONTAINER (self->switches);
		}
		return GTK_CONTAINER (self->vbox);
	}}
#line 470 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 175 "mixer-view.gob"
void 
xfce_mixer_view_pack_control (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p)
#line 476 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::pack_control"
#line 175 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 175 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 483 "xfce-mixer-view.c"
{
#line 176 "mixer-view.gob"
	
		GtkContainer *cont;
		GtkBox *box;
		gtk_widget_show (GTK_WIDGET (c));

		cont = self_find_container (self, p->location);

		if (GTK_IS_BOX (cont)) {
			box = GTK_BOX (cont);

			gtk_box_pack_start (box, GTK_WIDGET (c), FALSE, FALSE, 3);
		} else if ((gpointer)cont == (gpointer)self->switches) {
			gtk_table_attach_defaults (
				GTK_TABLE (self->switches),
				GTK_WIDGET (c),
				self->switches_c, self->switches_c + 1,
				self->switches_r, self->switches_r + 1
			);

			self->switches_c ++;
			if (self->switches_c >= SWITCH_COLUMNS) {
				self->switches_c = 0;
				self->switches_r++;
			}
		}
	}}
#line 512 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 203 "mixer-view.gob"
void 
xfce_mixer_view_set_profile (XfceMixerView * self, XfceMixerProfile * p)
#line 518 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::set_profile"
#line 203 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 203 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 525 "xfce-mixer-view.c"
{
#line 204 "mixer-view.gob"
	
		GList *g, *go;
		t_mixer_profile_item *item;
		XfceMixerControl *c;
		if (self->profile) {
			xfce_mixer_profile_unregister_view (self->profile, self);
		}
		self_clear_controls (self);

		self->profile = p;

		self_view_cleared (self);

		if (p) {
			/* sort by location, orderno */
			/* create correct control */
			/* self_add_control */
			xfce_mixer_profile_register_view (self->profile, self);

			go = xfce_mixer_profile_get_control_list (p);
			g = go;
			while (g) {
				item = (t_mixer_profile_item *)g->data;

				c = xfce_mixer_control_factory_new_from_profile_item (item, self->kind);
				if (c) {
					self_add_control (self, c);
					self_pack_control (self, c, item);
				}

				g = g_list_next (g);
			}
			xfce_mixer_profile_free_control_list (p, go);
		}
	}}
#line 563 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 240 "mixer-view.gob"
XfceMixerProfile const * 
xfce_mixer_view_get_profile (XfceMixerView * self)
#line 569 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::get_profile"
#line 240 "mixer-view.gob"
	g_return_val_if_fail (self != NULL, (XfceMixerProfile const * )0);
#line 240 "mixer-view.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_VIEW (self), (XfceMixerProfile const * )0);
#line 576 "xfce-mixer-view.c"
{
#line 241 "mixer-view.gob"
	
		return (self->profile);
	}}
#line 582 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 245 "mixer-view.gob"
void 
xfce_mixer_view_view_item_updated (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p)
#line 588 "xfce-mixer-view.c"
{
	XfceMixerViewClass *klass;
#line 245 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 245 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 595 "xfce-mixer-view.c"
	klass = XFCE_MIXER_VIEW_GET_CLASS(self);

	if(klass->view_item_updated)
		(*klass->view_item_updated)(self,c,p);
}
#line 245 "mixer-view.gob"
static void 
___real_xfce_mixer_view_view_item_updated (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p)
#line 604 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::view_item_updated"
{
#line 246 "mixer-view.gob"
	
		GtkBox *box;
		GtkContainer *cont, *cont2;
		if (p->orderno == -1) {
			self_del_control (self, c);
			return;
		}

		cont = self_find_container (self, p->location);
		cont2 = NULL;

		if (c) { /* was present before */
			cont2 = self_find_container (self, c->location);
			if (cont2 && cont2 == cont) { /* stayed in same container */
				box = GTK_BOX (cont);
				gtk_box_reorder_child (box, GTK_WIDGET (c), p->orderno);
				return;
			}
		}

		if (c) { /* was present before, and something is very different */
			/* unpack */
			self_del_control (self, c);
		}

		c = xfce_mixer_control_factory_new_from_profile_item (p, self->kind);
		if (c) {
			self_add_control (self, c);
			self_pack_control (self, c, p);
		}
	}}
#line 640 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 278 "mixer-view.gob"
void 
xfce_mixer_view_view_cleared (XfceMixerView * self)
#line 646 "xfce-mixer-view.c"
{
	XfceMixerViewClass *klass;
#line 278 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 278 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 653 "xfce-mixer-view.c"
	klass = XFCE_MIXER_VIEW_GET_CLASS(self);

	if(klass->view_cleared)
		(*klass->view_cleared)(self);
}
#line 278 "mixer-view.gob"
static void 
___real_xfce_mixer_view_view_cleared (XfceMixerView * self)
#line 662 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::view_cleared"
{
#line 279 "mixer-view.gob"
	
		self_clear_controls (self);
	}}
#line 670 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 283 "mixer-view.gob"
void 
xfce_mixer_view_profile_cleared (XfceMixerView * self)
#line 676 "xfce-mixer-view.c"
{
	XfceMixerViewClass *klass;
#line 283 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 283 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 683 "xfce-mixer-view.c"
	klass = XFCE_MIXER_VIEW_GET_CLASS(self);

	if(klass->profile_cleared)
		(*klass->profile_cleared)(self);
}
#line 283 "mixer-view.gob"
static void 
___real_xfce_mixer_view_profile_cleared (XfceMixerView * self)
#line 692 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::profile_cleared"
{
#line 284 "mixer-view.gob"
	
		self_view_cleared (self);
	}}
#line 700 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__

#line 288 "mixer-view.gob"
void 
xfce_mixer_view_profile_item_updated (XfceMixerView * self, t_mixer_profile_item * p)
#line 706 "xfce-mixer-view.c"
{
	XfceMixerViewClass *klass;
#line 288 "mixer-view.gob"
	g_return_if_fail (self != NULL);
#line 288 "mixer-view.gob"
	g_return_if_fail (XFCE_IS_MIXER_VIEW (self));
#line 713 "xfce-mixer-view.c"
	klass = XFCE_MIXER_VIEW_GET_CLASS(self);

	if(klass->profile_item_updated)
		(*klass->profile_item_updated)(self,p);
}
#line 288 "mixer-view.gob"
static void 
___real_xfce_mixer_view_profile_item_updated (XfceMixerView * self, t_mixer_profile_item * p)
#line 722 "xfce-mixer-view.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:View::profile_item_updated"
{
#line 289 "mixer-view.gob"
	
		/* vcname: name of the add/del/upd'd control */
		gchar *s;
		GList *g;
		XfceMixerControl *control;
		gboolean found;

		g = self->controls;
		if (!p || !p->vcname)
			return;

		/*TRACEY ("profile_item_updated for %s\n", p->vcname);*/
		found = FALSE;

		while (g) {
			control = XFCE_MIXER_CONTROL (g->data);
			if (control) {
				g_object_get (G_OBJECT (control), XFCE_MIXER_CONTROL_GET_PROP_VCNAME (&s), NULL );
				if (s) {
					if (g_str_equal (s, p->vcname)) {
						/*TRACEY ("=> %s\n", s);*/
						self_view_item_updated (self, control, p);
						found = TRUE;
					}
					g_free (s);
				}
			}
			g = g_list_next (g);
		}

		if (!found) {
			self_view_item_updated (self, NULL, p);
		}
	}}
#line 761 "xfce-mixer-view.c"
#undef __GOB_FUNCTION__


#if (!defined __GNUC__) || (defined __GNUC__ && defined __STRICT_ANSI__)
/*REALLY BAD HACK
  This is to avoid unused warnings if you don't call
  some method.  I need to find a better way to do
  this, not needed in GCC since we use some gcc
  extentions to make saner, faster code */
static void
___xfce_mixer_view_really_bad_hack_to_avoid_warnings(void)
{
	((void (*)(void))GET_NEW_VARG)();
	((void (*)(void))self_add_control)();
	((void (*)(void))self_del_control)();
	((void (*)(void))self_new)();
	((void (*)(void))self_clear_controls)();
	((void (*)(void))self_toggled_cb)();
	((void (*)(void))self_init_containers)();
	((void (*)(void))self_find_container)();
	((void (*)(void))self_pack_control)();
	((void (*)(void))self_set_profile)();
	((void (*)(void))self_get_profile)();
	((void (*)(void))self_view_item_updated)();
	((void (*)(void))self_view_cleared)();
	((void (*)(void))self_profile_cleared)();
	((void (*)(void))self_profile_item_updated)();
	___xfce_mixer_view_really_bad_hack_to_avoid_warnings();
}
#endif /* !__GNUC__ || (__GNUC__ && __STRICT_ANSI__) */

