/*
** EPITECH PROJECT, 2017
** File Name : texture.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics.h>

#define TX_TILE 0
#define TX_TILE_ACTIVABLE 1

typedef struct config_setting_t config_setting_t;

typedef struct rectangle_s {
	sfIntRect rect;
	const char *name;
} rectangle_t;

typedef struct texture_s {
	const char *name;
	sfTexture *texture;
	rectangle_t **rects;
} texture_t;

texture_t *get_texture_by_name(texture_t **textures, char const *name);

sfIntRect *get_texture_rect_by_name(texture_t *texture, char const *name);

int set_texture_by_setting(texture_t **textures, sfRectangleShape *rect,
	config_setting_t *parent);

rectangle_t *get_rect(texture_t *texture, char *name);

#endif
