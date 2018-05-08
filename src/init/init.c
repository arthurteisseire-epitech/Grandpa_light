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

static const init_arr_t init_arr[] = {
	init_event,
	init_config,
	init_musics,
	init_textures,
	init_player,
	init_scenes,
	init_clock,
	init_window,
	NULL
};

int init(rpg_t *rpg)
{
	int i = 0;

	while (init_arr[i] != NULL) {
		DR(init_arr[i](rpg));
		i++;
	}
	rpg->curr_scene = FIRST_SCENE;
	return (SUCCESS);
}
