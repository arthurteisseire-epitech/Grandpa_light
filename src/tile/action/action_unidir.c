/*
** EPITECH PROJECT, 2017
** File Name : action_unidir.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "tile.h"
#include "define.h"

int action_unidir(rpg_t __attribute((unused))*rpg, tile_t *tile)
{
	if (tile->direction == RIGHT)
		tile->direction = LEFT;
	else if (tile->direction == LEFT)
		tile->direction = RIGHT;
	if (tile->direction == UP)
		tile->direction = DOWN;
	else if (tile->direction == DOWN)
		tile->direction = UP;
	return (SUCCESS);
}
