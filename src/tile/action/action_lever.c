/*
** EPITECH PROJECT, 2017
** File Name : action_lever.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "texture.h"
#include "define.h"
#include "achievement.h"

int action_lever(rpg_t *rpg, tile_t *tile)
{
	if (tile->chanel == 15) {
		rpg->is_darkness = 0;
		new_achievement(rpg, "end");
	}
	shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
	apply_on_map(rpg, set_tile_by_chanel, tile);
	return (SUCCESS);
}
