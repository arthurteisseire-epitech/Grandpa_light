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
#include "texture.h"
#include "define.h"

int parse_image(scene_t *scene, texture_t **tx, sfImage *image)
{
	int status = SUCCESS;

	for (unsigned int row = 0; row < scene->size.y; row++) {
		status = fill_map_row(scene, tx, image, row);
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int fill_map_row(scene_t *scene, texture_t **tx, sfImage *image, int row)
{
	int status;
	sfColor color;
	int index;

	for (unsigned int col = 0;  col < scene->size.x; col++) {
		color = sfImage_getPixel(image, row, col);
		index = index_tile_by_color(color);
		scene->map[row][col] = malloc(sizeof(map_t));
		if (scene->map[row][col] == NULL)
			return (MALLOC_FAILED);
		status = init_tile(&scene->map[row][col]->tile, tx, index);
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int init_tile(tile_t **tile, texture_t **tx, int index_tile)
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
	(*tile)->chanel = 0;
	//(*tile)->texture = tx[tile_list[index_tile].idx_texture]->texture;
	return (SUCCESS);
}
