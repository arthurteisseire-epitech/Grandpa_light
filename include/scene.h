/*
** EPITECH PROJECT, 2017
** File Name : scene.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics/Types.h>

#define FIRST_SCENE 0

typedef struct sprite_s sprite_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;
typedef struct button_s button_t;

typedef struct map_s {
	sfVector2u size;
	tile_t ***tiles;
	sfVector2i start;
	sfVector2i end;
} map_t;

typedef struct scene_s {
	map_t *map;
	button_t **buttons;
	sfText **text;
} scene_t;

#endif
