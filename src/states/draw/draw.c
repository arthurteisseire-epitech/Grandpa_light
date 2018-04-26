/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "define.h"
#include "states.h"

int draw(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->window, sfBlack);
	sfRenderWindow_display(rpg->window);
	draw_scene(rpg, rpg->scenes[rpg->curr_scene]);
	return (SUCCESS);
}
