/*
** EPITECH PROJECT, 2017
** File Name : game_loop.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "window.h"
#include "states.h"

int game_loop(rpg_t *rpg)
{
	int status = 0;

	while (sfRenderWindow_isOpen(rpg->win->window)) {
		status = states(rpg);
		if (status != 0)
			return (status);
	}
	return (status);
}
