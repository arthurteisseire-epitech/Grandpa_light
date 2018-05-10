/*
** EPITECH PROJECT, 2017
** File Name : tile_action.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "tile.h"
#include "define.h"

int exec_tile(rpg_t *rpg, tile_t *tile)
{
	if (tile->func != NULL && tile->is_action) {
		swap_lasers(rpg);
		tile->func(rpg, tile);
		swap_lasers_back(rpg);
	}
	return (SUCCESS);
}
