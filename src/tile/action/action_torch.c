/*
** EPITECH PROJECT, 2017
** File Name : action_torch.c
** File description:
** Ozz
*/

#include "tile.h"
#include "rpg.h"
#include "scene.h"
#include "define.h"
#include "player.h"

int refresh_torch(rpg_t __attribute((unused))*rpg, tile_t *tile)
{
	tile->active = !tile->active;
	generate_shader(CURR_SCENE->map, rpg->player);
	generate_shader(CURR_SCENE->map, rpg->player);
	update_shader(CURR_SCENE->map);
	return (SUCCESS);
}
