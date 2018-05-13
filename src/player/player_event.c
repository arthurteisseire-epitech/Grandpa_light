/*
** EPITECH PROJECT, 2017
** File Name : player_event.c
** File description:
** by Arthur Teisseire
*/

#include <malloc.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "event.h"
#include "player.h"
#include "tile.h"
#include "tool.h"
#include "define.h"

void player_rotation(rpg_t *rpg)
{
	if (!my_strcmp(RPG_TILE(rpg, rpg->player->pos)->name, LAS_STR))
		rotate_laser(rpg, RPG_TILE(rpg, rpg->player->pos));
	if (rpg->event->key.code == sfKeyUp)
		rotate_player(rpg, DIR_UP);
	if (rpg->event->key.code == sfKeyLeft)
		rotate_player(rpg, DIR_LEFT);
	if (rpg->event->key.code == sfKeyDown)
		rotate_player(rpg, DIR_DOWN);
	if (rpg->event->key.code == sfKeyRight)
		rotate_player(rpg, DIR_RIGHT);
}

void player_movement(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyZ) {
		move_player(rpg, &rpg->player->pos, MOVE_UP);
		rotate_player(rpg, DIR_UP);
	}
	if (rpg->event->key.code == sfKeyQ) {
		move_player(rpg, &rpg->player->pos, MOVE_LEFT);
		rotate_player(rpg, DIR_LEFT);
	}
	if (rpg->event->key.code == sfKeyS) {
		move_player(rpg, &rpg->player->pos, MOVE_DOWN);
		rotate_player(rpg, DIR_DOWN);
	}
	if (rpg->event->key.code == sfKeyD) {
		move_player(rpg, &rpg->player->pos, MOVE_RIGHT);
		rotate_player(rpg, DIR_RIGHT);
	}
}

int player_action(rpg_t *rpg)
{
	static sfVector2i pos;
	static tile_t *tile;

	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		pos.x = (int)rpg->player->pos.x;
		pos.y = (int)rpg->player->pos.y;
		tile = CURR_SCENE->map->tiles[pos.x][pos.y];
		DR(exec_tile(rpg, tile));
	}
	return (SUCCESS);
}

int player_event(rpg_t *rpg)
{
	DR(player_action(rpg));
	if (RPG_SCENE(rpg)->event != event_dialog) {
		player_rotation(rpg);
		player_movement(rpg);
	}
	return (SUCCESS);
}