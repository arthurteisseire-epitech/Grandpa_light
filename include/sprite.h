/*
** EPITECH PROJECT, 2017
** File Name : sprite.h
** File description:
** by Arthur Teisseire
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.h>

typedef struct texture_s texture_t;

typedef struct sprite_s {
	sfSprite *sprite;
	texture_t *texture;
} sprite_t;

#endif
