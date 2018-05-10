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

int action_door(rpg_t __attribute((unused))*rpg, tile_t *tile)
{
	shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
	tile->active = !tile->active;
	tile->player_col = !tile->active;
	tile->laser_col = !tile->active;
	return (SUCCESS);
}
