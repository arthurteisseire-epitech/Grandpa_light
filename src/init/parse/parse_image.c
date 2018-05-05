/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <SFML/Graphics/Rect.h>
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
	int status;
	sfColor color;
	int index;

	for (unsigned int col = 0; col < map->size.x; col++) {
		color = sfImage_getPixel(image, row, col);
		index = index_tile_by_color(color);
		map->tiles[row][col] = malloc(sizeof(tile_t));
		if (map->tiles[row][col] == NULL)
			return (MALLOC_FAILED);
		set_tile_values(map->tiles[row][col], index, (sfVector2f){row, col}, color);
		status = init_tile(rpg, map->tiles[row][col], index,
			(sfVector2f){row, col});
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

static laser_t *init_laser(sfVector2f pos)
{
	laser_t *laser = malloc(sizeof(laser_t));

	if (laser == NULL)
		return (NULL);
	laser->vertical = 1;
	laser->horizontal = 1;
	laser->rect = sfRectangleShape_create();
	if (laser->rect == NULL)
		return (free(laser), NULL);
	sfRectangleShape_setFillColor(laser->rect, sfRed);
	sfRectangleShape_setPosition(laser->rect,
		coord_mult(pos, (sfVector2i){SIZE_TILE, SIZE_TILE}));
	sfRectangleShape_setTextureRect(laser->rect,
		(sfIntRect){(int)pos.x, (int)pos.y, SIZE_TILE, SIZE_TILE});
	sfRectangleShape_setScale(laser->rect, (sfVector2f){1, 1});
	return (laser);
}

void set_tile_values(tile_t *tile, int index_tile, sfVector2f pos, sfColor color)
{
	tile->name = tile_list[index_tile].name;
	tile->func = tile_list[index_tile].func;
	tile->player_col = tile_list[index_tile].player_col;
	tile->laser_col = tile_list[index_tile].laser_col;
	tile->is_action = tile_list[index_tile].is_action;
	tile->active = (char)color.r & 0b00000001;
	tile->direction = (char)color.r & 0b00000110;
	tile->chanel = (char)color.g & 0x0f;
	tile->sprite = sfSprite_create();
	tile->laser = init_laser(pos);
	tile->light = sfRectangleShape_create();
	tile->light_level = 0.1;
	tile->lighted = 0;
	tile->index_rect = 0;
}

int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos)
{
	texture_t *texture = rpg->tx_tile[tile_list[index_tile].idx_texture];

	if (tile->sprite == NULL || tile->laser == NULL || tile->light == NULL)
		return (MALLOC_FAILED);
	sfRectangleShape_setPosition(tile->light, scale_vec(pos, SIZE_TILE));
	sfRectangleShape_setSize(tile->light
			, (sfVector2f){SIZE_TILE, SIZE_TILE});
	sfSprite_setTexture(tile->sprite, texture->texture, sfTrue);
	sfSprite_setTextureRect(tile->sprite,
		get_rect(texture, tile->name)->rect);
	sfSprite_setPosition(tile->sprite,
		coord_mult(pos, (sfVector2i){SIZE_TILE, SIZE_TILE}));
	sfSprite_setScale(tile->sprite, (sfVector2f){1, 1});
	return (SUCCESS);
}
