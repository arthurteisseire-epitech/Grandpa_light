/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "define.h"
#include "player.h"
#include "tile.h"
#include "particule.h"

int update(rpg_t *rpg)
{
	if (CURR_SCENE->map != NULL) {
		set_player_pos(rpg->player);
		player_part(rpg->player);
		update_anim_tiles(rpg, rpg->clock);
		animate_sprite(rpg->player, rpg->clock);
	}
	return (SUCCESS);
}
