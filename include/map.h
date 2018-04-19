/*
** EPITECH PROJECT, 2017
** File Name : map.h
** File description:
** by Arthur Teisseire
*/

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;

typedef struct tile_s {
	sfSprite *sprite;
	char accessible;
	int (*action)(rpg_t *rpg);
} tile_t;

typedef struct map_s {
	sfFloatRect *rect;
	tile_t ***tiles;
} map_t;

#endif
