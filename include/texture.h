/*
** EPITECH PROJECT, 2017
** File Name : texture.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics/Types.h>

#define TX_TILE_WALL 0
#define TX_TILE_GROUND 1
#define TX_TILE_GLASS 2
#define TX_TILE_SPAWN 3
#define TX_TILE_END 4
#define TX_TILE_DOOR 5
#define TX_TILE_SWITCH 6
#define TX_TILE_LS_BEAM 7
#define TX_TILE_LS_RECEPTOR 8

typedef struct config_setting_t config_setting_t;

typedef struct rectangle_s {
	sfIntRect rect;
	const char *name;
} rectangle_t;

typedef struct texture_s {
	sfTexture *texture;
	rectangle_t **rects;
	const char *name;
} texture_t;

texture_t *get_texture_by_name(texture_t **textures, char const *name);
sfIntRect *get_texture_rect_by_name(texture_t *texture, char const *name);
int set_texture_by_setting(texture_t **textures, sfRectangleShape *rect, config_setting_t *parent);

#endif
