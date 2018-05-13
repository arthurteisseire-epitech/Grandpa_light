/*
** EPITECH PROJECT, 2017
** File Name : rotate_player.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "tile.h"
#include "player.h"
#include "scene.h"

void rotate_player(rpg_t *rpg, float angle)
{
	sfRectangleShape_setRotation(rpg->player->rect, angle);
	generate_shader(rpg->scenes[rpg->curr_scene]->map, rpg->player);
	update_shader(rpg->scenes[rpg->curr_scene]->map);
}
