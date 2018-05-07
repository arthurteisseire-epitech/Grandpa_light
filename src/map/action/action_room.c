/*
** EPITECH PROJECT, 2017
** File Name : action_room.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "scene.h"
#include "define.h"

int action_room(rpg_t *rpg, tile_t *tile)
{
	rpg->curr_scene = tile->chanel;
	if (rpg->scenes[rpg->curr_scene]->map != NULL)
		place_in_spawn(rpg);
	return (SUCCESS);
}
