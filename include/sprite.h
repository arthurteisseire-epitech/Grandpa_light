/*
** EPITECH PROJECT, 2017
** File Name : sprite.h
** File description:
** by Arthur Teisseire
*/

#ifndef SRPITE_H
#define SRPITE_H

#include <SFML/Graphics/Types.h>

typedef struct sprite_s {
	sfSprite *sprite;
	unsigned char is_visible;
} sprite_t;

#endif
