/*
** EPITECH PROJECT, 2017
** File Name : destroy_scene.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"

static void destroy_tile(tile_t *tile)
{
	sfSprite_destroy(tile->sprite);
	free(tile);
}

static void destroy_map(map_t *map)
{
	for (unsigned int row = 0; row < map->size.y; row++) {
		for (unsigned int col = 0; col < map->size.x; col++)
			destroy_tile(map->tiles[row][col]);
		free(map->tiles[row]);
	}
	free(map->tiles);
	free(map);
}

void destroy_scene(scene_t *scene)
{
	destroy_map(scene->map);
	free(scene);
}

void destroy_scenes(scene_t **scenes)
{
	int i = 0;

	while (scenes[i] != NULL) {
		destroy_scene(scenes[i]);
		i++;
	}
}
