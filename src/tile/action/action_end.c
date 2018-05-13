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
#include "player.h"
#include "define.h"

static void update_stats(rpg_t *rpg, tile_t *tile)
{
	rpg->player->stats->xp += (tile->chanel + 1) * 3;
	while (rpg->player->stats->xp >= rpg->player->stats->xp_to_up) {
		rpg->player->stats->xp -= rpg->player->stats->xp_to_up;
		rpg->player->stats->xp_to_up += 5;
		rpg->player->stats->level++;
		rpg->player->stats->light_radius += 
			(rpg->player->stats->level + 1) * 20;
	}
}

int action_end(rpg_t *rpg, tile_t *tile)
{
	tile_t *room;

	if (CURR_SCENE->completed == FALSE)
		update_stats(rpg, tile);
	CURR_SCENE->completed = TRUE;
	rpg->curr_scene = SC_HUB;
	rpg->prev_scene = rpg->curr_scene;
	if (CURR_SCENE->map == NULL)
		return (SUCCESS);
	place_in_spawn(rpg);
	room = apply_on_map(rpg, get_tile_by_chanel, tile);
	if (room == CURR_SCENE->map->tiles[0][0])
		return (SUCCESS);
	if (!room->active) {
		room->active = TRUE;
		shift_texture_rect(room->rect, room->tx, &room->curr_frame);
	}
	return (SUCCESS);
}
