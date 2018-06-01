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

void rotate_player(rpg_t *rpg, float __attribute((unused))angle)
{
	generate_shader(CURR_SCENE->map, rpg->player);
	update_shader(rpg, CURR_SCENE->map);
}
