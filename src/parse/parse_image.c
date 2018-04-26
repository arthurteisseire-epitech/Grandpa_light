/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "parse.h"
#include "scene.h"
#include "tile.h"
#include "define.h"

void init_tile(tile_t *tile, int index_tile)
{
	if (index_tile == -1)
		return;
	tile->name = tile_list[index_tile].name;
	tile->action = tile_list[index_tile].action;
	tile->player_col = tile_list[index_tile].player_col;
	tile->laser_col = tile_list[index_tile].laser_col;
	tile->direction = 0;
	tile->active = 0;
}

int parse_image(scene_t *scene, char *path)
{
	sfImage *image = sfImage_createFromFile(path);
	sfVector2u size = sfImage_getSize(image);
	sfColor color;
	int index;

	if (image == NULL)
		return (WRONG_PATH);
	for (unsigned int col = 0; col < size.x; col++) {
		for (unsigned int row = 0; row < size.y; row++) {
			color = sfImage_getPixel(image, row, col);
			index = index_tile_by_color(color);
			init_tile(scene->map[row][col]->tile, index);
		}
	}
	return (SUCCESS);
}
