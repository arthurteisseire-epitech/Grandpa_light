/*
** EPITECH PROJECT, 2017
** File Name : change_scene.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "camera.h"
#include "define.h"
#include "player.h"
#include "particule.h"
#include "tile.h"
#include "tool.h"

void place_in_spawn(rpg_t *rpg)
{
	rpg->player->pos = get_pos_tile_by_name(
		CURR_SCENE->map, tile_pos_line, "spawn");
	update_shader(rpg, CURR_SCENE->map);
	rotate_player(rpg, DIR_UP);
	clean_particules(rpg->player->particule);
}
