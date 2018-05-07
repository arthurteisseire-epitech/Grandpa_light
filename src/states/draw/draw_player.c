/*
** EPITECH PROJECT, 2017
** File Name : draw_player.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "player.h"

void draw_player(rpg_t *rpg)
{
	sfRenderWindow_drawRectangleShape(rpg->window, rpg->player->rect,
	NULL);
}
