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
	shift_texture_rect(rpg->tx_tile, tile);
	tile->player_col = !tile->player_col;
	tile->laser_col = !tile->laser_col;
	return (SUCCESS);
}
