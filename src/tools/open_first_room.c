/*
** EPITECH PROJECT, 2017
** File Name : open_first_room.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "texture.h"
#include "scene.h"
#include "tile.h"

void set_rect(tile_t *tile)
{
	if (tile->chanel == 1)
		shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
}

void open_first_room(rpg_t *rpg)
{
	int row = 0;
	int col = 0;
	map_t *map = rpg->scenes[SC_HUB]->map;

	while (map->tiles[row] != NULL) {
		col = 0;
		while (map->tiles[row][col] != NULL) {
			set_rect(map->tiles[row][col]);
			col++;
		}
		row++;
	}
}

