/*
** EPITECH PROJECT, 2017
** File Name : init.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "init.h"
#include "define.h"
#include "scene.h"

int init(rpg_t *rpg)
{
	int status = SUCCESS;

	status = init_window(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_event(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_scenes(rpg);
	if (status != SUCCESS)
		return (status);
	rpg->curr_scene = FIRST_SCENE;
	return (status);
}
