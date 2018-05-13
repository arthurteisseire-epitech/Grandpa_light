/*
** EPITECH PROJECT, 2017
** File Name : button_setting.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "define.h"

int button_setting(rpg_t *rpg)
{
	rpg->curr_scene = SC_HUB;
	if (CURR_SCENE->map != NULL)
		place_in_spawn(rpg);
	return (SUCCESS);
}
