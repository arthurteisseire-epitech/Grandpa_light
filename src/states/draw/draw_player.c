/*
** EPITECH PROJECT, 2017
** File Name : draw_player.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "player.h"
#include "button.h"
#include "states.h"

void draw_player(rpg_t *rpg)
{
	sfRenderWindow_drawVertexArray(rpg->window, rpg->player->part, NULL);
	sfRenderWindow_drawRectangleShape(rpg->window, rpg->player->rect,
	NULL);
	draw_buttons(rpg, rpg->player->items);
}
