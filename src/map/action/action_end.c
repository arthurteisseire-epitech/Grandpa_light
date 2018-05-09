/*
** EPITECH PROJECT, 2017
** File Name : action_end.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "texture.h"
#include "define.h"

int action_end(rpg_t *rpg, tile_t *tile)
{
	tile_t *room;

	rpg->curr_scene = SC_HUB;
	if (rpg->scenes[rpg->curr_scene]->map == NULL)
		return (SUCCESS);
	place_in_spawn(rpg);
	room = apply_on_map(rpg, get_tile_by_chanel, tile);
	if (room == rpg->scenes[rpg->curr_scene]->map->tiles[0][0])
		return (SUCCESS);
	if (!room->active) {
		room->active = TRUE;
		shift_texture_rect(room->rect, room->tx, &room->curr_frame);
	}
	return (SUCCESS);
}
