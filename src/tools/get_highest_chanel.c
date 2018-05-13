/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "tool.h"
#include "define.h"
#include "my.h"

static void higher_chanel_in_line(tile_t **tiles, int *highest_chanel, int size)
{
	for (int i = 0; i < size; i++)
		if (tiles[i]->active &&
			my_strcmp(tiles[i]->name, ROOM_STR) == 0 &&
			*highest_chanel < tiles[i]->chanel)
			*highest_chanel = tiles[i]->chanel;
}

int get_highest_active_chanel(map_t const *map)
{
	int highest_chanel = 0;

	for (int i = 0; i < (int)map->size.x; i++)
		higher_chanel_in_line(map->tiles[i], &highest_chanel,
			map->size.y);
	return (highest_chanel);
}