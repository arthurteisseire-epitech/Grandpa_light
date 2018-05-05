/*
** EPITECH PROJECT, 2017
** File Name : rotate_player.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "tile.h"
#include "character.h"
#include "scene.h"

void rotate_player(rpg_t *rpg, float angle, sfVector2f dir)
{
	sfRectangleShape_setRotation(rpg->character->rect, angle);
	generate_shader(rpg->scenes[rpg->curr_scene]->map, rpg->character->pos, dir);
	update_shader(rpg->scenes[rpg->curr_scene]->map);
}
