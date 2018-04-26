/*
** EPITECH PROJECT, 2017
** File Name : object.h
** File description:
** by Arthur Teisseire
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.h>

#define MASK_NAME(color) ((color).b & 0x0f)
#define NB_TILE 1

typedef struct sprite_s sprite_t;
typedef struct rpg_s rpg_t;

typedef struct tile_s {
	sprite_t *sprite;
	char *name;
	int active;
	char direction;
	int player_col;
	int laser_col;
	int (*action)(rpg_t *, struct tile_s *);
} tile_t;

typedef struct tile_list_s {
	sfColor color;
	char *name;
	int player_col;
	int laser_col;
	int (*action)(rpg_t *, struct tile_s *);
} tile_list_t;

extern const tile_list_t tile_list[NB_TILE];

int index_tile_by_color(sfColor color);

#endif