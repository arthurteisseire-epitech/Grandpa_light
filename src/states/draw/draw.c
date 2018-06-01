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
#include "particule.h"
#include "player.h"
#include "init.h"

void draw_raycast_circle(rpg_t *rpg)
{
	int i = 0;
	sfRectangleShape **rc_c =
		CURR_SCENE->map->raycast_circle;

	while (rc_c[i] != NULL) {
		sfRenderWindow_drawRectangleShape(rpg->window, rc_c[i], NULL);
		i++;
	}
}

void draw_debug(rpg_t *rpg)
{
	if (CURR_SCENE->map->raycast_circle != NULL)
		draw_raycast_circle(rpg);
}

int draw(rpg_t *rpg)
{
	sfRenderWindow_clear(rpg->window, sfBlack);
	draw_scene(rpg, CURR_SCENE);
	if (CURR_SCENE->map != NULL) {
		sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
		draw_player(rpg);
		DR(player_room_indicate(rpg, rpg->player));
	} else {
		sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
		draw_cursor(rpg);
	}
	draw_on_achievement(rpg);
	sfRenderWindow_display(rpg->window);
	return (SUCCESS);
}
