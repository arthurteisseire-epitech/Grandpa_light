/*
** EPITECH PROJECT, 2017
** File Name : player_event.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "define.h"
#include "character.h"
#include "tile.h"

void player_rotation(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyUp)
		rotate_player(rpg, DIR_UP, MOVE_UP);
	if (rpg->event->key.code == sfKeyLeft)
		rotate_player(rpg, DIR_LEFT, MOVE_LEFT);
	if (rpg->event->key.code == sfKeyDown)
		rotate_player(rpg, DIR_DOWN, MOVE_DOWN);
	if (rpg->event->key.code == sfKeyRight)
		rotate_player(rpg, DIR_RIGHT, MOVE_RIGHT);
}

void player_movement(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyZ) {
		move_player(rpg, &rpg->character->pos, MOVE_UP);
		rotate_player(rpg, DIR_UP, MOVE_UP);
	}
	if (rpg->event->key.code == sfKeyQ) {
		move_player(rpg, &rpg->character->pos, MOVE_LEFT);
		rotate_player(rpg, DIR_LEFT, MOVE_LEFT);
	}
	if (rpg->event->key.code == sfKeyS) {
		move_player(rpg, &rpg->character->pos, MOVE_DOWN);
		rotate_player(rpg, DIR_DOWN, MOVE_DOWN);
	}
	if (rpg->event->key.code == sfKeyD) {
		move_player(rpg, &rpg->character->pos, MOVE_RIGHT);
		rotate_player(rpg, DIR_RIGHT, MOVE_RIGHT);
	}
}

void player_action(rpg_t *rpg)
{
	static sfVector2i pos;
	static tile_t *tile;

	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		pos.x = rpg->character->pos.x;
		pos.y = rpg->character->pos.y;
		tile = rpg->scenes[rpg->curr_scene]->map->tiles[pos.x][pos.y];
		if (tile->func != NULL && tile->is_action)
			tile->func(rpg, tile);
	}
}

int player_event(rpg_t *rpg)
{
	if (rpg->scenes[rpg->curr_scene]->map != NULL) {
		player_rotation(rpg);
		player_action(rpg);
		player_movement(rpg);
	}
	return (SUCCESS);
}
