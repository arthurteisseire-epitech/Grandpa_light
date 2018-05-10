/*
** EPITECH PROJECT, 2017
** File Name : get_tile_pos.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "scene.h"
#include "tile.h"

sfVector2f get_pos_tile_by_name(map_t *map, pos_tile_t func, void *name)
{
	int y = 0;
	float x = 0;

	while (map->tiles[y]) {
		x = func(map, map->tiles[y], name);
		if (x != -1)
			return ((sfVector2f){y, x});
		y++;
	}
	return ((sfVector2f){0.0, 0.0});
}

int tile_pos_line(map_t __attribute((unused))*map, tile_t **tiles, void *name)
{
	int i = 0;

	while (tiles[i]) {
		if (my_strcmp(tiles[i]->name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
