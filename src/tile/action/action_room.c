/*
** EPITECH PROJECT, 2017
** File Name : action_room.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "texture.h"
#include "scene.h"
#include "define.h"

int action_room(rpg_t *rpg, tile_t *tile)
{
	if (!tile->active)
		return (SUCCESS);
	rpg->curr_scene = tile->chanel;
	rpg->prev_scene = rpg->curr_scene;
	if (CURR_SCENE->map != NULL)
		place_in_spawn(rpg);
	return (SUCCESS);
}
