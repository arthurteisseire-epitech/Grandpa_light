/*
** EPITECH PROJECT, 2017
** File Name : get_tile.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"
#include "scene.h"
#include "tile.h"

tile_t *get_map_tile(map_t *map, get_tile_t func, void *data)
{
	tile_t *tile;
	int i = 0;

	while (map->tiles[i]) {
		tile = func(map->tiles[i], data);
		if (tile != NULL)
			return (tile);
		i++;
	}
	return (map->tiles[0][0]);
}

tile_t *get_tile_by_name(tile_t **tiles, void *name)
{
	int i = 0;

	while (tiles[i]) {
		if (my_strcmp(tiles[i]->name, name) == 0)
			return (tiles[i]);
		i++;
	}
	return (NULL);
}

tile_t *get_tile_by_chanel(tile_t **tiles, void *chanel)
{
	int i = 0;
	int nb = *(int *)chanel;

	while (tiles[i]) {
		if (nb == tiles[i]->chanel)
			return (tiles[i]);
		i++;
	}
	return (NULL);
}
