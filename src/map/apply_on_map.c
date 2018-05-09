/*
** EPITECH PROJECT, 2017
** File Name : get_tile.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"

tile_t *apply_on_map(rpg_t *rpg, get_tile_t func, void *data)
{
	tile_t *tile;
	int i = 0;
	map_t *map = rpg->scenes[rpg->curr_scene]->map;

	while (map->tiles[i]) {
		tile = func(rpg, map->tiles[i], data);
		if (tile != NULL)
			return (tile);
		i++;
	}
	return (map->tiles[0][0]);
}

tile_t *get_tile_by_name(rpg_t *rpg, tile_t **tiles, void *name)
{
	int i = 0;

	(void)rpg;
	while (tiles[i]) {
		if (my_strcmp(tiles[i]->name, name) == 0)
			return (tiles[i]);
		i++;
	}
	return (NULL);
}

tile_t *set_tile_by_chanel(rpg_t *rpg, tile_t **tiles, void *data)
{
	int i = 0;
	tile_t *tile = data;

	while (tiles[i]) {
		if (tile->chanel == tiles[i]->chanel &&
		tiles[i]->func != NULL && !tiles[i]->is_action)
			tiles[i]->func(rpg, tiles[i]);
		i++;
	}
	return (NULL);
}

tile_t *get_tile_by_chanel(rpg_t *rpg, tile_t **tiles, void *data)
{
	int i = 0;
	tile_t *tile = data;

	(void)rpg;
	while (tiles[i]) {
		if (tile->chanel == tiles[i]->chanel)
			return (tiles[i]);
		i++;
	}
	return (NULL);
}
