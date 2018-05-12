/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event.h
*/

#ifndef EVENT_H_
#define EVENT_H_

typedef struct rpg_s rpg_t;
typedef int (*scene_func_t)(rpg_t *);

int event_menu(rpg_t *rpg);
void handle_exit_key(rpg_t *rpg);
int handle_events(rpg_t *rpg);
int menu_status(rpg_t *rpg);

#ifndef NB_FT_SCENE
	#define NB_FT_SCENE 2
#endif

typedef struct ft_scene_s {
	char *name;
	scene_func_t scene_func;
} ft_scene_t;

static const ft_scene_t ft_scene[] = {
	{"default", handle_events},
	{"menu", event_menu},
	{"menu_status", menu_status},
};


#endif
