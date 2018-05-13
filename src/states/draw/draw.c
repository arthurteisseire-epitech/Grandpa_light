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
#include "tile.h"
#include "tool.h"

void draw_raycast_circle(rpg_t *rpg)
{
	int i = 0;
	sfRectangleShape **rc_c = 
		rpg->scenes[rpg->curr_scene]->map->raycast_circle;

	while (rc_c[i] != NULL) {
		sfRenderWindow_drawRectangleShape(rpg->window,rc_c[i] , NULL);
		i++;
	}
}

void draw_debug(rpg_t *rpg)
{
	if (rpg->scenes[rpg->curr_scene]->map->raycast_circle != NULL)
		draw_raycast_circle(rpg);
}

int draw(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->window, sfBlack);
	draw_scene(rpg, rpg->scenes[rpg->curr_scene]);
	if (rpg->scenes[rpg->curr_scene]->map != NULL) {
		draw_player(rpg);
		draw_laser_particule(rpg);
	}
	sfRenderWindow_display(rpg->window);
	return (SUCCESS);
}
