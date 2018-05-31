/*
** EPITECH PROJECT, 2017
** File Name : reset_player_stats.c
** File description:
** by Arthur Teisseire
*/

#include "player.h"

void reset_player_stats(player_t *player)
{
	player->stats->level = 0;
	player->stats->xp = 0;
	player->stats->xp_to_up = 10;
	player->stats->light_radius = 120;
	player->stats->nb_orbe = 0;
}
