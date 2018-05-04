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

static const int (*init[])(rpg_t *) = {
	init_event,
	init_config,
	init_textures,
	init_scenes,
	init_window,
	init_clock,
	NULL
};

int init(rpg_t *rpg)
{
	int status = SUCCESS;
	int i = 0;

	while (init[i] != NULL) {
		status = init[i](rpg);
		if (status != SUCCESS)
			return (status);
		i++;
	}
	rpg->curr_scene = FIRST_SCENE;
	destroy_config(rpg->config);
	return (status);
}
