/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** return to menu from pause
*/

#include "rpg.h"
#include "scene.h"
#include "define.h"

int button_pause(rpg_t *rpg)
{
	rpg->curr_scene = SCENE_MENU;
	return (SUCCESS);
}
