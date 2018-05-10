/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "define.h"
#include "tile.h"
#include "rpg.h"
#include "texture.h"

int action_laser_captor(rpg_t *rpg, tile_t *tile)
{
	shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
	apply_on_map(rpg, set_tile_by_chanel, tile);
	return (SUCCESS);
}
