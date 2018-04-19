/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>

#define NB_SCENES 0
#define TITLE "rpg"
#define MALLOC_FAILED -2

typedef struct scene_s scene_t;
typedef struct menu_s menu_t;
typedef struct texture_s texture_t;
typedef struct window_s window_t;
typedef struct event_s event_t;

typedef struct game_s {
	scene_t *scenes[NB_SCENES + 1];
} game_t;

typedef struct rpg_s {
	sfEvent *event;
	window_t *win;
	menu_t *menu;
	game_t *puzzle;
	game_t *rpg;
	texture_t **textures;
} rpg_t;

int game_loop(rpg_t *rpg);

#endif
