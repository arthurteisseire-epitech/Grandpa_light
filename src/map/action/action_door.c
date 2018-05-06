/*
** EPITECH PROJECT, 2017
** File Name : action_door.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "texture.h"
#include "tile.h"
#include "define.h"

int action_door(rpg_t *rpg, tile_t *tile)
{
	texture_t *texture = get_texture_by_name(rpg->tx_tile, tile->name);

	if (texture->rects[tile->index_rect + 1] == NULL)
		tile->index_rect = 0;
	else
		tile->index_rect++;
	sfSprite_setTextureRect(tile->sprite
		, texture->rects[tile->index_rect]->rect);
	tile->player_col = !tile->player_col;
	tile->laser_col = !tile->laser_col;
	return (SUCCESS);
}
