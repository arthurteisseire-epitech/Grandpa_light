/*
** EPITECH PROJECT, 2017
** File Name : action_unlocker.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "tile.h"
#include "player.h"
#include "define.h"
#include "scene.h"
#include "tool.h"

static tile_t *get_door(rpg_t *rpg, tile_t *tile)
{
	sfVector2f pos[4] = {
		{tile->pos.x + 1, tile->pos.y},
		{tile->pos.x - 1, tile->pos.y},
		{tile->pos.x, tile->pos.y + 1},
		{tile->pos.x, tile->pos.y - 1},
	};
	tile_t *door = NULL;

	for (int i = 0; i < 4; i++) {
		if (IN_MAP(pos[i], CURR_SCENE->map) &&
		my_strcmp(RPG_TILE(rpg, pos[i])->name, DOOR_STR) == 0) {
			door = RPG_TILE(rpg, pos[i]);
			break;
		}
	}
	return (door);
}

int action_unlocker(rpg_t *rpg, tile_t *tile)
{
	tile_t *door = get_door(rpg, tile);

	printf("toot\n");
	if (door && rpg->player->stats->nb_orbe >= tile->chanel
	&& !door->active) {
		printf("nb_orb: %d, door->chanel: %d\n", rpg->player->stats->nb_orbe, door->chanel);
		rpg->player->stats->nb_orbe -= tile->chanel;
		action_door(rpg, door);
	}
	return (SUCCESS);
}
