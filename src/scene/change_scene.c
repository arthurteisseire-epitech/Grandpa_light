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
#include "tile.h"
#include "tool.h"

void place_in_spawn(rpg_t *rpg)
{
	rpg->player->pos = get_pos_tile_by_name(
		rpg->scenes[rpg->curr_scene]->map, tile_pos_line, "spawn");
	update_shader(rpg->scenes[rpg->curr_scene]->map);	
	rotate_player(rpg, DIR_UP);
}

void change_scene(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyP)) {
		rpg->curr_scene = (rpg->curr_scene + 1) % rpg->nb_scenes;
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			place_in_spawn(rpg);
	} else if (sfKeyboard_isKeyPressed(sfKeyO)) {
		rpg->curr_scene = (rpg->curr_scene == 0) ?
			rpg->nb_scenes - 1 : rpg->curr_scene - 1;
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			place_in_spawn(rpg);
	}
}
