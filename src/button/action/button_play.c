/*
** EPITECH PROJECT, 2017
** File Name : button_play.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "define.h"

int button_play(rpg_t *rpg)
{
	rpg->prev_scene = SC_HUB;
	rpg->curr_scene = SC_HUB;
	if (CURR_SCENE->map != NULL)
		place_in_spawn(rpg);
	reset_scenes(rpg);
	return (SUCCESS);
}
