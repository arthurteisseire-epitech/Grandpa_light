/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "parse.h"
#include "init.h"
#include "define.h"

int parse_image(scene_t *scene, sfImage *image, sfVector2u size)
{
	int status = SUCCESS;

	for (unsigned int row = 0; row < size.y; row++) {
		status = fill_map_row(scene->map, image, size, row);
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int fill_map_row(map_t ***map, sfImage *image, sfVector2u size, int row)
{
	int status;
	sfColor color;
	int index;

	for (unsigned int col = 0;  col < size.x; col++) {
		color = sfImage_getPixel(image, row, col);
		index = index_tile_by_color(color);
		map[row][col] = malloc(sizeof(map_t));
		if (map[row][col] == NULL)
			return (MALLOC_FAILED);
		status = init_tile(&map[row][col]->tile, index);
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int init_tile(tile_t **tile, int index_tile)
{
	if (index_tile == -1)
		return (SUCCESS);
	(*tile) = malloc(sizeof(tile_t));
	if (*tile == NULL)
		return (MALLOC_FAILED);
	(*tile)->name = tile_list[index_tile].name;
	(*tile)->action = tile_list[index_tile].action;
	(*tile)->player_col = tile_list[index_tile].player_col;
	(*tile)->laser_col = tile_list[index_tile].laser_col;
	(*tile)->direction = 0;
	(*tile)->active = 0;
	return (SUCCESS);
}
