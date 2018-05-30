/*
** EPITECH PROJECT, 2017
** File Name : destroy_player.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "player.h"
#include "particule.h"
#include "destroy.h"

void destroy_player(player_t *player)
{
	if (player == NULL)
		return;
	sfRectangleShape_destroy(player->rect);
	destroy_buttons(player->items);
	destroy_particule(player->particule);
	free(player->stats);
	free(player->anim);
	free(player);
}
