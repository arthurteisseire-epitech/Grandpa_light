/*
** EPITECH PROJECT, 2017
** File Name : scene.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCENE_H
#define SCENE_H

#define NB_SCENES 0

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct map map_t;
typedef struct sprite sprite_t;

typedef struct scene {
	map_t *map;
	sprite_t **sprites;
} scene_t;

#endif
