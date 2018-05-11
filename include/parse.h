/*
** EPITECH PROJECT, 2017
** File Name : parse.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARSE_H
#define PARSE_H

#include <SFML/Graphics/Types.h>

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;
typedef struct map_s map_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;

int parse_image_line(rpg_t *rpg, map_t *map, sfImage *image, int row);

int fill_map_row(rpg_t *rpg, map_t *map, sfImage *image, int row);

int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos);
void set_tile_values(tile_t *tile, int index_tile, sfVector2f pos,
	sfColor color);

#endif
