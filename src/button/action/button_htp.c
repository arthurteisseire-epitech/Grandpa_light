/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** htp button
*/

#include "rpg.h"
#include "define.h"
#include "scene.h"

int button_htp(rpg_t *rpg)
{
	rpg->curr_scene = SC_HTP;
	return (SUCCESS);
}