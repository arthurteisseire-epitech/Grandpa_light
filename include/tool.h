/*
** EPITECH PROJECT, 2017
** File Name : tool.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOL_H
#define TOOL_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct tile_s tile_t;

int is_pos_in_rect(sfVector2i pos, sfFloatRect rect);
void inverse(unsigned int *a, unsigned int *b);
void set_rect(tile_t *tile);
void open_first_room(rpg_t *rpg);

map_t *rpg_map(rpg_t *rpg);
tile_t *map_tile(map_t *map, sfVector2f pos);
tile_t ***rpg_tiles(rpg_t *rpg);
scene_t *rpg_scene(rpg_t *rpg);

#endif
