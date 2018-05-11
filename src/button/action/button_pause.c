/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** return to game from pause
*/

#include "rpg.h"
#include "scene.h"
#include "define.h"

int button_pase(rpg_t *rpg)
{
	rpg->curr_scene = rpg->scene_paused;
	return (SUCCESS);
}
