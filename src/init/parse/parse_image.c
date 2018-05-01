/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
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

rectangle_t *get_rect(texture_t *texture, char *name)
{
	int i = 0;	

	while (texture->rects[i] != NULL) {
		if (my_strcmp(texture->rects[i]->name, name) == 0)
			return (texture->rects[i]);
		i++;
	}
	return (texture->rects[0]);
}

int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos)
{
	texture_t *texture = rpg->tx_tile[tile_list[index_tile].idx_texture];

	tile->name = tile_list[index_tile].name;
	tile->action = tile_list[index_tile].action;
	tile->player_col = tile_list[index_tile].player_col;
	tile->laser_col = tile_list[index_tile].laser_col;
	tile->active = (tile_list[index_tile].color.r & 0b00000001);
	tile->direction = (tile_list[index_tile].color.r & 0b00000110);
	tile->chanel = (tile_list[index_tile].color.g & 0x0f);
	tile->sprite = sfSprite_create();
	if (tile->sprite == NULL)
		return (MALLOC_FAILED);
	sfSprite_setTexture(tile->sprite, texture->texture, sfTrue);
	sfSprite_setTextureRect(tile->sprite, get_rect(texture, tile->name)->rect);
	sfSprite_setPosition(tile->sprite,
			mult(pos, (sfVector2i){SIZE_TILE, SIZE_TILE}));
	sfSprite_setScale(tile->sprite, (sfVector2f){1, 1});
	return (SUCCESS);
}
