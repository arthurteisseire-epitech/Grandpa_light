/*
** EPITECH PROJECT, 2017
** File Name : map.h
** File description:
** by Arthur Teisseire
*/

#ifndef MAP_H
#define MAP_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct tile {
	sfSprite *sprite;
	char accessible;
	int (*action)(rpg_t *rpg);
} tile_t;

typedef struct map {
	sfFloatRect *rect;
	tile_t ***tiles;
} map_t;
