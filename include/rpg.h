/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

#define NB_SCENES 0

typedef struct scene scene_t;
typedef struct menu menu_t;
typedef struct texture texture_t;

typedef struct game {
	sfEvent *event;
	sfRenderWindow *window;
	scene_t *scenes[NB_SCENES + 1];
} game_t;

typedef struct rpg {
	menu_t *menu;
	game_t *puzzle;
	game_t *rpg;
	texture_t **textures;
} rpg_t;

#endif
