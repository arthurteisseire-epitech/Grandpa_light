/*
** EPITECH PROJECT, 2017
** File Name : player_particules.c
** File description:
** by Arthur Teisseire
*/

#include "player.h"
#include "tile.h"
#include "particule.h"

void player_part(player_t *player)
{
	player->particule->rect.left = player->pos.x * SIZE_TILE;
	player->particule->rect.top = player->pos.y * SIZE_TILE;
	player->particule->rect.height = SIZE_TILE;
	player->particule->rect.width = SIZE_TILE;
	gen_particules(player->particule);
}
