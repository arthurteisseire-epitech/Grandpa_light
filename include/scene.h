/*
** EPITECH PROJECT, 2017
** File Name : scene.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.h>

typedef struct map_s map_t;
typedef struct sprite_s sprite_t;

typedef struct scene_s {
	map_t *map;
	sprite_t **sprites;
} scene_t;

#endif
