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
#include "destroy.h"

static void destroy_laser(laser_t *laser)
{
	sfRectangleShape_destroy(laser->rect);
	free(laser);
}

static void destroy_tile(tile_t *tile)
{
	sfSprite_destroy(tile->sprite);
	destroy_laser(tile->laser);
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
	if (scene->map != NULL)
		destroy_map(scene->map);
	if (scene->buttons != NULL)
		destroy_buttons(scene->buttons);
	if (scene->text != NULL)
		destroy_texts(scene->text);
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