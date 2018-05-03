/*
** EPITECH PROJECT, 2017
** File Name : init.c
** File description:
** by Arthur Teisseire
*/

#include "destroy.h"
#include "rpg.h"
#include "init.h"
#include "define.h"
#include "scene.h"

int init(rpg_t *rpg)
{
	int status = 0;
	int (*init[INIT_NB])(rpg_t *) = {init_event, init_config, init_textures,
		init_scenes, init_window, init_clock};

	for (unsigned int i = 0; i < INIT_NB; i++) {
		status = init[i](rpg);
		if (status != SUCCESS)
			return (status);
	}/*
	status = init_event(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_config(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_textures(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_scenes(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_window(rpg);
	if (status != SUCCESS)
		return (status);
	status = init_clock(rpg);
	if (status != SUCCESS)
		return (status);*/
	rpg->curr_scene = FIRST_SCENE;
	destroy_config(rpg->config);
	return (status);
}