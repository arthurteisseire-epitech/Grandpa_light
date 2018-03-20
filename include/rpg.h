/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>

typedef struct texture {
	sfTexture *texture;
	sfRectShape *rect;
} texture_t;

typedef struct sprite {
	sfSprite *sprite;
	sfRectShape *rect;
	texture_t *;
} sprite_t;

typedef struct game {
	texture_t **texture_arr;
} game_t;

typedef struct rpg {
	game_t *true_game;
	game_t *false_game;
} rpg_t;

#endif
