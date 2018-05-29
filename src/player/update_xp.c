/*
** EPITECH PROJECT, 2017
** File Name : update_xp.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "player.h"

void update_xp(rpg_t *rpg, int xp)
{
	rpg->player->stats->xp += xp;
	while (rpg->player->stats->xp >= rpg->player->stats->xp_to_up) {
		rpg->player->stats->xp -= rpg->player->stats->xp_to_up;
		rpg->player->stats->xp_to_up += 5;
		rpg->player->stats->level++;
		rpg->player->stats->light_radius = RAYCAST_RADIUS
			+ rpg->player->stats->level * 20;
	}
}
