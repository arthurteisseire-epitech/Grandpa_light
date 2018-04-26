/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>

#define NB_SCENES 1
#define TITLE "rpg"

typedef struct scene_s scene_t;
typedef struct menu_s menu_t;
typedef struct texture_s texture_t;
typedef struct window_s window_t;
typedef struct event_s event_t;

typedef struct rpg_s {
	sfEvent *event;
	sfRenderWindow *window;
	scene_t **scenes;
	texture_t **textures;
	sfClock *clock;
	int curr_scene;
} rpg_t;

int game_loop(rpg_t *rpg);

#endif
