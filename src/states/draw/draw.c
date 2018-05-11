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
#include "scene.h"
#include "achievement.h"

int draw(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->window, sfBlack);
	draw_scene(rpg, rpg->scenes[rpg->curr_scene]);
	if (rpg->scenes[rpg->curr_scene]->map != NULL)
		draw_player(rpg);
	sfRenderWindow_display(rpg->window);
	return (SUCCESS);
}
