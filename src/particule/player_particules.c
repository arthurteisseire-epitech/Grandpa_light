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
	sfFloatRect r;

	r.left = player->pos.x * SIZE_TILE;
	r.top = player->pos.y * SIZE_TILE;
	r.height = SIZE_TILE;
	r.width = SIZE_TILE;
	gen_particules(player->part, r, NB_PLAYER_PART, &player->index_part);
}
