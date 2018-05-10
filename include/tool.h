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

#define RPG_MAP(rpg) ((rpg)->scenes[(rpg)->curr_scene]->map)
#define MAP_TILE(map, pos) (map->tiles[(int)(pos.x)][(int)(pos.y)])
#define RPG_TILES(rpg) ((rpg)->scenes[(rpg)->curr_scene]->map->tiles)
#define RPG_TILE(rpg) (MAP_TILE(RPG_MAP((rpg))))
#define RPG_SCENE(rpg) ((rpg)->scenes[(rpg)->curr_scene])
#define IN_MAP (pos.x < map->size.x && pos.y < map->size.y && pos.x > 0 &&\
pos.y > 0)

#endif
