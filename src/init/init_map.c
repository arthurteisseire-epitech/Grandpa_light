/*
** EPITECH PROJECT, 2017
** File Name : init_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "define.h"
#include "parse.h"

int init_map(rpg_t *rpg, scene_t *scene, const char *path)
{
	map_t *map;
	sfImage *image = sfImage_createFromFile(path);
	
	if (image == NULL)
		return (WRONG_PATH);
	scene->map = malloc(sizeof(map_t));
	map = scene->map;
	map->size = sfImage_getSize(image);
	map->tiles = malloc(sizeof(tile_t **) * (scene->map->size.y + 1));
	if (scene->map == NULL)
		return (MALLOC_FAILED);
	for (unsigned int row = 0; row < map->size.y; row++) {
		map->tiles[row] = malloc(sizeof(tile_t *) * (map->size.x + 1));
		if (map->tiles[row] == NULL)
			return (MALLOC_FAILED);
		map->tiles[row][map->size.x] = NULL;
		if (parse_image_line(rpg, map, image, row) == -1)
			return (-1);
	}
	map->tiles[map->size.y] = NULL;
	return (SUCCESS);
}
