/*
** EPITECH PROJECT, 2017
** File Name : texture.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics/Types.h>

#define TX_WALL 0
#define TX_GROUND 1
#define TX_GLASS 2
#define TX_SPAWN 3
#define TX_END 4
#define TX_DOOR 5
#define TX_SWITCH 6
#define TX_LS_BEAM 7
#define TX_LS_RECEPTOR 7

typedef struct texture_s {
	sfTexture *texture;
	sfIntRect *rect;
} texture_t;

#endif
