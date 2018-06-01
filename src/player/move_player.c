/*
** EPITECH PROJECT, 2017
** File Name : move_player.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "player.h"
#include "tile.h"
#include "scene.h"
#include "vec.h"

char unidir_col(tile_t *tile, sfVector2f move)
{
	sfVector2f tile_dir = get_direction(tile->direction);

	if (move.x && tile_dir.x)
		return (move.x != tile_dir.x);
	else if (move.y && tile_dir.y)
		return (move.y != tile_dir.y);
	return (0);
}

char is_in_map(map_t *map, sfVector2f pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (0);
	else if ((unsigned int)pos.x >= map->size.x
			|| (unsigned int)pos.y >= (map->size.y))
		return (0);
	else
		return (1);
}

char collide(map_t *map, sfVector2f pos, sfVector2f move)
{
	tile_t *tile = NULL;

	if (is_in_map(map, pos)) {
		tile = map->tiles[(int)pos.x][(int)pos.y];
		if (tile->func == action_unidir)
			return (unidir_col(tile, move));
		else
			return (map->tiles[(int)pos.x][(int)pos.y]->player_col);
	} else
		return (1);
}

void move_player(rpg_t *rpg, sfVector2f *pos, sfVector2f move)
{
	sfVector2f new_pos = add_vec(*pos, move);

	if (!collide(CURR_SCENE->map, new_pos, move)) {
		*pos = new_pos;
	}
}

void set_player_pos(player_t *player)
{
	sfRectangleShape_setPosition(player->rect,
			add_vec(scale_vec(player->pos, SIZE_TILE),
			VEC_HALF_TILE));
}
