/*
** EPITECH PROJECT, 2017
** File Name : game_loop.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "window.h"
#include "states.h"
#include "define.h"

int game_loop(rpg_t *rpg)
{
	int status = SUCCESS;

	while (sfRenderWindow_isOpen(rpg->win->window)) {
		status = states(rpg);
		if (status != SUCCESS)
			return (status);
	}
	return (status);
}
