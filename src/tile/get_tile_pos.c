/*
** EPITECH PROJECT, 2017
** File Name : get_tile_pos.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
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

static sfVector2f *get_pos_tile_line(map_t *map, tile_t *tile, int y)
{
	int x = 0;
	sfVector2f *pos = malloc(sizeof(sfVector2f));

	if (pos == NULL)
		return (NULL);
	while (map->tiles[x][y] != NULL) {
		if (map->tiles[x][y] == tile) {
			pos->x = x;
			pos->y = y;
			return (pos);
		}
		x++;
	}
	return (NULL);
}

sfVector2f get_pos_tile(map_t *map, tile_t *tile)
{
	int y = 0;
	sfVector2f *pos = NULL;
	sfVector2f res;

	while (map->tiles[y] != NULL) {
		pos = get_pos_tile_line(map, tile, y);
		if (pos != NULL) {
			res = *pos;
			return (free(pos), res);
		}
		free(pos);
		y++;
	}
	return ((sfVector2f){0, 0});
}
