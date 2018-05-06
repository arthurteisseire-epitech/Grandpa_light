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
	shift_texture_rect(rpg->tx_tile, tile);
	apply_on_map(rpg, set_tile_by_chanel, tile);
	return (SUCCESS);
}
