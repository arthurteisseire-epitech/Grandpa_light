/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "window.h"
#include "define.h"

int draw(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->win->window, sfBlack);
	sfRenderWindow_display(rpg->win->window);
	return (SUCCESS);
}
