/*
** EPITECH PROJECT, 2017
** File Name : scene.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.h>

typedef struct sprite_s sprite_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;

typedef struct map_s {
	tile_t *tile;
	sfVector2i start;
	sfVector2i end;
} map_t;

typedef struct scene_s {
	sfVector2u size;
	map_t ***map;
} scene_t;

#endif
