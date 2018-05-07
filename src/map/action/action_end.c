/*
** EPITECH PROJECT, 2017
** File Name : action_end.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "define.h"

int action_end(rpg_t *rpg, tile_t __attribute((unused))*tile)
{
	rpg->curr_scene = SC_HUB;
	if (rpg->scenes[rpg->curr_scene]->map != NULL)
		place_in_spawn(rpg);
	return (SUCCESS);
}
