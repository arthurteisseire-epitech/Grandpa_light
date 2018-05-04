/*
** EPITECH PROJECT, 2017
** File Name : action_door.c
** File description:
** by Arthur Teisseire
*/

#include "scene.h"
#include "tile.h"
#include "define.h"

int action_door(map_t __attribute((unused))*map, tile_t *tile)
{
	tile->player_col = !tile->player_col;
	tile->laser_col = !tile->laser_col;
	return (SUCCESS);
}
