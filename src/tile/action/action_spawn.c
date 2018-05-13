/*
** EPITECH PROJECT, 2017
** File Name : action_spawn.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "scene.h"
#include "define.h"

int action_spawn(rpg_t *rpg, tile_t __attribute((unused))*tile)
{
	rpg->curr_scene = SC_HUB;
	place_in_spawn(rpg);
	return (SUCCESS);
}
