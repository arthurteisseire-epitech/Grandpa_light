/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "rpg.h"
#include "destroy.h"

void destroy(rpg_t *rpg)
{
	destroy_window(rpg->window);
	destroy_event(rpg->event);
	destroy_scenes(rpg->scenes);
	destroy_textures(rpg->tx_tile);
	destroy_textures(rpg->tx_game);
	destroy_musics(rpg->musics);
	destroy_player(rpg->player);
	destroy_achievement(rpg->achievement);
	destroy_config(rpg->config);
	sfClock_destroy(rpg->clock);
	free(rpg);
}
