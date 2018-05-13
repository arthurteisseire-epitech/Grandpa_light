/*
** EPITECH PROJECT, 2017
** File Name : action_end.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "texture.h"
#include "player.h"
#include "init.h"
#include "define.h"

static void update_stats(rpg_t *rpg, tile_t *tile)
{
	rpg->player->stats->xp += (tile->chanel + 1) * 3;
	while (rpg->player->stats->xp >= rpg->player->stats->xp_to_up) {
		rpg->player->stats->xp -= rpg->player->stats->xp_to_up;
		rpg->player->stats->xp_to_up += 5;
		rpg->player->stats->level++;
		rpg->player->stats->nb_orbe++;
		rpg->player->stats->light_radius += 
			(rpg->player->stats->level + 1) * 20;
	}
}

static int change_tile(rpg_t *rpg, tile_t *tile)
{
	int index = index_tile_by_name(GROUND_STR);

	tile->name = tile_list[index].name;
	tile->func = tile_list[index].func;
	DR(init_tile(rpg, tile, index, tile->pos));
	return (SUCCESS);
}

int action_end(rpg_t *rpg, tile_t *tile)
{
	tile_t *room;

	if (rpg->scenes[rpg->curr_scene]->completed == FALSE)
		update_stats(rpg, tile);
	rpg->scenes[rpg->curr_scene]->completed = TRUE;
	if (rpg->scenes[SC_HUB]->map == NULL)
		return (SUCCESS);
	rpg->prev_scene = rpg->curr_scene;
	rpg->curr_scene = SC_HUB;
	room = apply_on_map(rpg, get_tile_by_chanel, tile);
	rpg->curr_scene = rpg->prev_scene;
	if (room == rpg->scenes[SC_HUB]->map->tiles[0][0])
		return (SUCCESS);
	if (!room->active) {
		room->active = TRUE;
		shift_texture_rect(room->rect, room->tx, &room->curr_frame);
	}
	DR(change_tile(rpg, tile));
	return (SUCCESS);
}
