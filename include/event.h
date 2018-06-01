/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event.h
*/

#ifndef EVENT_H_
#define EVENT_H_

#define EVENT_DELTA_TIME 0.1f

typedef struct rpg_s rpg_t;
typedef int (*scene_func_t)(rpg_t *);

int event_menu(rpg_t *rpg);
void handle_exit_key(rpg_t *rpg);
int event_pause(rpg_t *rpg);
int event_map(rpg_t *rpg);
int event_settings(rpg_t *rpg);
int menu_status(rpg_t *rpg);
int event_dialog(rpg_t *rpg);
int handle_pause_key(rpg_t *rpg);

#ifndef NB_FT_SCENE
	#define NB_FT_SCENE 6
#endif

typedef struct ft_scene_s {
	char *name;
	scene_func_t scene_func;
} ft_scene_t;

static const ft_scene_t ft_scene[NB_FT_SCENE] = {
	{"default", event_map},
	{"menu", event_menu},
	{"pause", event_pause},
	{"menu_status", menu_status},
	{"settings", event_settings},
	{"event_dialog", event_dialog},
};

#endif
