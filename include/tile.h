/*
** EPITECH PROJECT, 2017
** File Name : tile.h
** File description:
** by Arthur Teisseire
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics/Types.h>

#define MASK_NAME(color) ((color).b & 0x0f)
#define NB_TILE 5
#define SIZE_TILE 32

typedef struct sprite_s sprite_t;
typedef struct rpg_s rpg_t;
typedef struct texture_s texture_t;

typedef struct tile_s {
	char *name;
	int active;
	char direction;
	int chanel;
	int player_col;
	int laser_col;
	int (*action)(rpg_t *, struct tile_s *);
	sfSprite *sprite;
} tile_t;

typedef struct tile_list_s {
	sfColor color;
	char *name;
	int player_col;
	int laser_col;
	int (*action)(rpg_t *, struct tile_s *);
	int idx_texture;
} tile_list_t;

extern const tile_list_t tile_list[NB_TILE];

int index_tile_by_color(sfColor color);

#endif
