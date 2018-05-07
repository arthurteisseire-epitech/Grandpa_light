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
	rpg->curr_scene = SC_HUB;
	if (rpg->scenes[rpg->curr_scene]->map != NULL)
		place_in_spawn(rpg);
	return (SUCCESS);
}
