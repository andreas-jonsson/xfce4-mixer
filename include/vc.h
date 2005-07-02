/*
 * Copyright (c) 2003 Danny Milosavljevic <danny_milo@yahoo.com>
 * Copyright (c) 2003 Benedikt Meurer <benny@xfce.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __VC_H
#define __VC_H
#include <glib.h>

/* this is the volume changer stuff */

typedef void (*volchanger_callback_t)(char const *which, void *privdata);

typedef enum {
	CT_SLIDER = 0,
	CT_ONOFF = 1,
	CT_SELECT = 2
} volcontrol_type_t;

typedef struct {
        char *name;

	void (*vc_set_device)(char const *dev);
	int (*vc_reinit_device)(void);
        int (*vc_get_volume)(char const *which);
        void (*vc_set_volume)(char const *which, int v);
        GList *(*vc_get_control_list)(void);
        void (*vc_set_volume_callback)(volchanger_callback_t cb, void *privdata);
        void (*vc_close_device)(void);
        GList *(*vc_get_device_list)(void);
	void (*vc_set_select)(char const *which, gchar const *v);
	gchar *(*vc_get_select)(char const *which);
	gboolean (*vc_get_switch)(char const *which);
	void (*vc_set_switch)(char const *which, gboolean b);
	char const *(*vc_get_device)(void);
	void (*vc_handle_events)(void);
} volchanger_t;

typedef struct {
	char *		name;
	/*int		cnt_channels; TODO */
	
	volcontrol_type_t	type;
	
	/* only for type == CT_SELECT: */
	GList		*choices; /* list item = volchoice_t */
} volcontrol_t;

typedef struct {
  gchar* name;
  gchar* displayname;
} volchoice_t; /* choices entry for select */

void register_vc(volchanger_t *vc);
void unregister_vc(volchanger_t *vc);
void unregister_all(void);
void select_vc(char const *name);
void select_vc_direct(volchanger_t *vc);
volchanger_t *selected_vc();
volchanger_t **first_vc();
volchanger_t **next_vc(volchanger_t **);

#ifndef VC_PLUGIN
/* these operate on the selected_vc: */
int vc_get_volume(char const *which);
void vc_set_volume(char const *which, int v);
void vc_set_select(char const *which, gchar const *v);
gchar *vc_get_select(char const *which);
void vc_set_switch(char const *which, gboolean v);
gboolean vc_get_switch(char const *which);
void vc_handle_events(void);

/* returns list of volcontrol_t */
GList *vc_get_control_list();

void vc_free_control_list(GList *g);
void vc_free_choices(GList* choices);
volchoice_t* vc_choice_dup(const volchoice_t *choice);

void vc_set_volume_callback (volchanger_callback_t cb, void *data);
void vc_set_device(char const *which);
void vc_close_device();
char const *vc_get_device ();
GList *vc_get_device_list();
void vc_free_device_list(GList *device_list);
#elif defined(__GNUC__)
#define REGISTER_VC_PLUGIN(a) \
static volchanger_t vc = { \
        name: #a, \
        vc_set_device: vc_set_device, \
        vc_get_volume: vc_get_volume, \
        vc_set_volume: vc_set_volume, \
        vc_reinit_device: vc_reinit_device, \
        vc_get_control_list: vc_get_control_list, \
        vc_set_volume_callback: vc_set_volume_callback, \
        vc_close_device: vc_close_device, \
        vc_get_device_list: vc_get_device_list, \
        vc_set_select: vc_set_select, \
        vc_get_select: vc_get_select, \
        vc_get_switch: vc_get_switch, \
        vc_set_switch: vc_set_switch, \
        vc_get_device: vc_get_device, \
        vc_handle_events: vc_handle_events \
}; \
\
int register_##a(void) \
{ \
	if (init()) { \
	        register_vc(&vc); \
	} \
	else { \
		g_warning("Init of \"%s\" failed", #a); \
	} \
        return 0; \
}
#else
#define REGISTER_VC_PLUGIN(a) \
static volchanger_t vc = { \
        #a, \
        vc_set_device, \
        vc_reinit_device, \
        vc_get_volume, \
        vc_set_volume, \
        vc_get_control_list, \
        vc_set_volume_callback, \
        vc_close_device, \
        vc_get_device_list, \
        vc_get_select, \
        vc_get_switch, \
        vc_set_switch, \
        vc_get_device, \
        vc_handle_events \
}; \
\
int register_##a( ) \
{ \
	if (init()) { \
	        register_vc(&vc); \
	} \
	else { \
		g_warning("Init of \"%s\" failed", #a); \
	} \
        return 0; \
};
#endif

#endif /* ndef __VC_H */
