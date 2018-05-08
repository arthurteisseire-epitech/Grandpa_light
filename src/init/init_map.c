/*
** EPITECH PROJECT, 2017
** File Name : init_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "define.h"
#include "parse.h"
#include "tool.h"

static int init_row(rpg_t *rpg, map_t *map, sfImage *image, unsigned int row)
{
	int status;

	map->tiles[row] = malloc(sizeof(tile_t *) * (map->size.x + 1));
	if (map->tiles[row] == NULL)
		return (MALLOC_FAILED);
	map->tiles[row][map->size.x] = NULL;
	status = parse_image_line(rpg, map, image, row);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}

int init_map(rpg_t *rpg, map_t **map, const char *path)
{
	sfImage *image = sfImage_createFromFile(path);
	int status;

	if (image == NULL)
		return (WRONG_PATH);
	(*map) = malloc(sizeof(map_t));
	if ((*map) == NULL)
		return (MALLOC_FAILED);
	(*map)->size = sfImage_getSize(image);
	inverse(&(*map)->size.x, &(*map)->size.y);
	(*map)->tiles = malloc(sizeof(tile_t **) * ((*map)->size.y + 1));
	if ((*map)->tiles == NULL)
		return (MALLOC_FAILED);
	for (unsigned int row = 0; row < (*map)->size.y; row++) {
		status = init_row(rpg, *map, image, row);
		if (status != SUCCESS)
			return (status);
	}
	(*map)->tiles[(*map)->size.y] = NULL;
	inverse(&(*map)->size.x, &(*map)->size.y);
	return (SUCCESS);
}
