/*
** EPITECH PROJECT, 2017
** File Name : texture.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics/Types.h>

#define WALL 0
#define GROUND 1
//#define NAME index
//etc.

typedef struct texture_s {
	sfTexture *texture;
	sfIntRect *rect;
} texture_t;

#endif
