/*
** EPITECH PROJECT, 2017
** File Name : action_lever.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "texture.h"
#include "define.h"

int action_lever(rpg_t *rpg, tile_t *tile)
{
	texture_t *texture = get_texture_by_name(rpg->tx_tile, tile->name);

	if (texture->rects[tile->index_rect + 1] == NULL)
		tile->index_rect = 0;
	else
		tile->index_rect++;
	sfSprite_setTextureRect(tile->sprite
		, texture->rects[tile->index_rect]->rect);
	apply_on_map(rpg, set_tile_by_chanel, tile);
	return (SUCCESS);
}
