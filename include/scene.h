/*
** EPITECH PROJECT, 2017
** File Name : scene.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.h>

#define CURR_SCENE rpg->scenes[rpg->curr_scene]
#define SCENE_MENU 0
#define SC_HUB 4

#define FIRST_SCENE SCENE_MENU

#ifndef NB_FT_SCENE
	#define NB_FT_SCENE 1
#endif



typedef struct rpg_s rpg_t;
typedef struct sprite_s sprite_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;
typedef struct button_s button_t;

int loop_menu(rpg_t *rpg);

typedef struct map_s {
	sfVector2u size;
	tile_t ***tiles;
	sfVector2i start;
	sfVector2i end;
} map_t;

typedef int (*scene_func)(rpg_t *);


typedef struct scene_s {
	map_t *map;
	button_t **buttons;
	sfText **text;
	scene_func scene_loop;
} scene_t;

typedef struct ft_scene_s
{
	char *name;
	scene_func scene_func;
}ft_scene_t;

static const ft_scene_t ft_scene[] = {
	{"menu", loop_menu},
};

void change_scene(rpg_t *rpg);
void place_in_spawn(rpg_t *rpg);
int manage_button(rpg_t *rpg, button_t **button, sfEvent *event);

#endif
