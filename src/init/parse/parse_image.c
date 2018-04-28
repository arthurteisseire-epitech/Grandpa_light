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

static sfVector2f mult(sfVector2f v1, sfVector2i v2)
{
	return ((sfVector2f){v1.x * v2.x, v1.y * v2.y});
}

int parse_image_line(rpg_t *rpg, map_t *map, sfImage *image, int row)
{
	int status;
	sfColor color;
	int index;

	for (unsigned int col = 0; col < map->size.x; col++) {
		color = sfImage_getPixel(image, row, col);
		index = index_tile_by_color(color);
		map->tiles[row][col] = malloc(sizeof(tile_t));
		if (map->tiles[row][col] == NULL)
			return (MALLOC_FAILED);
		status = init_tile(rpg, map->tiles[row][col], index,
			(sfVector2f){row, col});
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos)
{
	tile->name = tile_list[index_tile].name;
	tile->action = tile_list[index_tile].action;
	tile->player_col = tile_list[index_tile].player_col;
	tile->laser_col = tile_list[index_tile].laser_col;
	tile->direction = 0;
	tile->active = 0;
	tile->chanel = 0;
	tile->sprite = sfSprite_create();
	if (tile->sprite == NULL)
		return (MALLOC_FAILED);
	sfSprite_setTexture(tile->sprite,
		rpg->textures[tile_list[index_tile].idx_texture]->texture,
		sfTrue);
	sfSprite_setPosition(tile->sprite,
		mult(pos, (sfVector2i){SIZE_TILE, SIZE_TILE}));
	//sfSprite_setScale(tile->sprite, (sfVector2f){SIZE_TILE, SIZE_TILE});
	return (SUCCESS);
}
