/*
** EPITECH PROJECT, 2017
** File Name : destroy_map.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "destroy.h"
#include "tile.h"
#include "scene.h"
#include "tool.h"

void destroy_raycast_circle(map_t *map)
{
	int i = 0;

	if (map->raycast_circle == NULL)
		return;
	while (map->raycast_circle[i] != NULL) {
		sfRectangleShape_destroy(map->raycast_circle[i]);
		i++;
	}
	free(map->raycast_circle);
	map->raycast_circle = NULL;
}

void destroy_laser(laser_t *laser)
{
	sfRectangleShape_destroy(laser->hor_rect);
	sfRectangleShape_destroy(laser->vert_rect);
	destroy_particule(laser->particule);
	free(laser);
}

void destroy_tile(tile_t *tile)
{
	sfRectangleShape_destroy(tile->rect);
	sfRectangleShape_destroy(tile->light);
	destroy_laser(tile->laser);
	free(tile);
}

void destroy_map(map_t *map)
{
	inverse(&map->size.x, &map->size.y);
	for (unsigned int row = 0; row < map->size.y; row++) {
		for (unsigned int col = 0; col < map->size.x; col++) {
			destroy_tile(map->tiles[row][col]);
		}
		free(map->tiles[row]);
	}
	destroy_raycast_circle(map);
	free(map->tiles);
	free(map);
}
