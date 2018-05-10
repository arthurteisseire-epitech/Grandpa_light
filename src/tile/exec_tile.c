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
	int *activated;

	if (tile->func != NULL && tile->is_action) {
		activated = swap_lasers(rpg);
		CM(activated);
		tile->func(rpg, tile);
		swap_lasers_back(rpg, activated);
		free(activated);
	}
	return (SUCCESS);
}
