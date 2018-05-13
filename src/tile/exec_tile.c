/*
** EPITECH PROJECT, 2017
** File Name : tile_action.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "define.h"
#include "tool.h"

int exec_tile(rpg_t *rpg, tile_t *tile)
{
	if (tile->func != NULL && tile->is_action) {
		if (tile->func != action_end)
			swap_lasers(rpg);
		tile->func(rpg, tile);
		if (tile->func != NULL && tile->func != action_end)
			swap_lasers_back(rpg);
		init_lasers(rpg);
	}
	return (SUCCESS);
}
