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
#include "particule.h"

void draw_player(rpg_t *rpg)
{
	sfRenderWindow_drawVertexArray(rpg->window
	, rpg->player->particule->vertex_array, NULL);
	sfRenderWindow_drawRectangleShape(rpg->window, rpg->player->rect, NULL);
	draw_buttons(rpg, rpg->player->items);
}
