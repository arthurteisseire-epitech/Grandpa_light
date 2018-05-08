/*
** EPITECH PROJECT, 2017
** File Name : game_loop.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "states.h"
#include "define.h"

int game_loop(rpg_t *rpg)
{
	while (sfRenderWindow_isOpen(rpg->window))
		DR(states(rpg));
	return (SUCCESS);
}
