/*
** EPITECH PROJECT, 2017
** File Name : get_tile_by_name.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"
#include "scene.h"
#include "tile.h"

tile_t *get_line_tile(tile_t **tiles, char *name)
{
	int i = 0;

	while (tiles[i]) {
		if (my_strcmp(tiles[i]->name, name) == 0)
			return (tiles[i]);
		i++;
	}
	return (NULL);
}

tile_t *get_map_tile(map_t *map, char *name)
{
	tile_t *tile;
	int i = 0;

	while (map->tiles[i]) {
		tile = get_line_tile(map->tiles[i], name);
		if (tile != NULL)
			return (tile);
		i++;
	}
	return (map->tiles[0][0]);
}
