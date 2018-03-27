/*
** EPITECH PROJECT, 2017
** File Name : sprite.h
** File description:
** by Arthur Teisseire
*/

#ifndef SPRITE_H
#define SPRITE_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct texture texture_t;

typedef struct sprite {
	sfSprite *sprite;
	texture_t *texture;
} sprite_t;

#endif
