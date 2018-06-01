/*
** EPITECH PROJECT, 2017
** File Name : action_unidir.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "tile.h"
#include "player.h"
#include "define.h"

int action_unidir(rpg_t __attribute((unused))*rpg, tile_t *tile)
{
	if (tile->direction == RIGHT) {
		tile->direction = LEFT;
		rotate_sprite(tile, DIR_LEFT);
	}
	else if (tile->direction == LEFT) {
		tile->direction = RIGHT;
		rotate_sprite(tile, DIR_RIGHT);
	}
	if (tile->direction == UP) {
		tile->direction = DOWN;
		rotate_sprite(tile, DIR_DOWN);
	}
	else if (tile->direction == DOWN) {
		tile->direction = UP;
		rotate_sprite(tile, DIR_UP);
	}
	return (SUCCESS);
}
