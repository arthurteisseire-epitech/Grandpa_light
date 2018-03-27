/*
** EPITECH PROJECT, 2017
** File Name : texture.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct texture {
	sfTexture *texture;
	sfRectShape *rect;
} texture_t;

#endif
