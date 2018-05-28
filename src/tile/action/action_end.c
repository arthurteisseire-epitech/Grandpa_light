/*
** EPITECH PROJECT, 2017
** File Name : action_end.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "texture.h"
#include "player.h"
#include "init.h"
#include "define.h"
#include "achievement.h"

static void update_stats(rpg_t *rpg, tile_t *tile)
{
	update_xp(rpg, (tile->chanel + 1) * 3);
	rpg->player->stats->nb_orbe++;
	set_inventory_text(rpg);
}

static void change_tile(rpg_t *rpg, tile_t *tile)
{
	int index = index_tile_by_name(GROUND_STR);
	texture_t *texture = rpg->tx_tile[tile_list[index].idx_texture];

	tile->name = tile_list[index].name;
	tile->func = tile_list[index].func;
	tile->tx = texture;
	tile->curr_frame = 0;
	sfRectangleShape_setTexture(tile->rect, texture->texture, sfTrue);
	sfRectangleShape_setTextureRect(tile->rect
	, get_rect(texture, tile->name)->rect);
	rm_anim_tile(CURR_SCENE->anim_tiles, tile);
}

static void update_room(rpg_t *rpg, tile_t *tile)
{
	tile_t *room;

	room = apply_on_map(rpg, get_tile_by_chanel, tile);
	rpg->curr_scene = rpg->prev_scene;
	if (room == rpg->scenes[SC_HUB]->map->tiles[0][0])
		return;
	if (!room->active) {
		room->active = TRUE;
		shift_texture_rect(room->rect, room->tx, &room->curr_frame);
	}
	change_tile(rpg, tile);
	generate_shader(CURR_SCENE->map, rpg->player);
	update_shader(CURR_SCENE->map);
	if (rpg->curr_scene == SCENE_MENU + 1)
		new_achievement(rpg, "first_map");
}

int action_end(rpg_t *rpg, tile_t *tile)
{
	if (CURR_SCENE->completed == FALSE)
		update_stats(rpg, tile);
	CURR_SCENE->completed = TRUE;
	if (rpg->scenes[SC_HUB]->map == NULL)
		return (SUCCESS);
	rpg->prev_scene = rpg->curr_scene;
	rpg->curr_scene = SC_HUB;
	apply_on_map(rpg, set_tile_by_chanel, tile);
	update_room(rpg, tile);
	return (SUCCESS);
}
