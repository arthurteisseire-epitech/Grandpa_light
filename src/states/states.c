/*
** EPITECH PROJECT, 2017
** File Name : states.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "states.h"
#include "define.h"
#include "scene.h"

int states(rpg_t *rpg)
{
	int status = SUCCESS;

	status = event(rpg);
	if (status != SUCCESS)
		return (status);
	status = update(rpg);
	if (status != SUCCESS)
		return (status);
	if (rpg->scenes[rpg->curr_scene]->scene_loop != NULL)
		status = rpg->scenes[rpg->curr_scene]->scene_loop(rpg);
	status = draw(rpg);
	if (status != SUCCESS)
		return (status);
	return (status);
}
