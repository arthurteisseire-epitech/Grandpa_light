/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "parse.h"
#include "init.h"
#include "texture.h"
#include "define.h"
#include "vec.h"

int parse_image_line(rpg_t *rpg, map_t *map, sfImage *image, int row)
{
	sfColor color;
	int index;

	for (unsigned int col = 0; col < map->size.x; col++) {
		color = sfImage_getPixel(image, row, col);
		index = index_tile_by_color(color);
		map->tiles[row][col] = malloc(sizeof(tile_t));
		CM(map->tiles[row][col]);
		DR(set_tile_values(map->tiles[row][col], index, (sfVector2f){row, col}, color));
		DR(init_tile(rpg, map->tiles[row][col], index,
			(sfVector2f){row, col}));
	}
	return (SUCCESS);
}

int set_tile_values(tile_t *tile, int index_tile, sfVector2f pos, sfColor color)
{
	tile->active = (char)(color.r & 0b00000001);
	tile->direction = (char)(color.r & 0b00000110);
	tile->chanel = (char)(color.g & 0x0f);
	tile->name = tile_list[index_tile].name;
	tile->func = tile_list[index_tile].func;
	tile->player_col = tile_list[index_tile].player_col;
	tile->laser_col = tile_list[index_tile].laser_col;
	tile->is_action = tile_list[index_tile].is_action;
	tile->rect = sfRectangleShape_create();
	tile->laser = init_laser(pos);
	tile->light = sfRectangleShape_create();
	CM(tile->rect);
	CM(tile->laser);
	CM(tile->light);
	tile->light_level = 0.1;
	tile->lighted = 0;
	tile->index_rect = 0;
	tile->curr_frame = 0;
	tile->pos = pos;
	return (SUCCESS);
}

int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos)
{
	texture_t *texture = rpg->tx_tile[tile_list[index_tile].idx_texture];

	if (tile->rect == NULL || tile->laser == NULL || tile->light == NULL)
		return (MALLOC_FAILED);
	sfRectangleShape_setPosition(tile->light, scale_vec(pos, SIZE_TILE));
	sfRectangleShape_setSize(tile->light,
		(sfVector2f){SIZE_TILE, SIZE_TILE});
	sfRectangleShape_setTexture(tile->rect, texture->texture, sfTrue);
	sfRectangleShape_setTextureRect(tile->rect,
		get_rect(texture, tile->name)->rect);
	sfRectangleShape_setPosition(tile->rect, scale_vec(pos, SIZE_TILE));
	sfRectangleShape_setSize(tile->rect,
		(sfVector2f){SIZE_TILE, SIZE_TILE});
	tile->tx = texture;
	return (SUCCESS);
}
