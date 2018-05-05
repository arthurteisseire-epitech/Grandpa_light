/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "camera.h"
#include "define.h"
#include "character.h"
#include "tile.h"
#include "tool.h"

static void handle_exit(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->window);
}

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

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_exit(rpg);
		if (rpg->event->type == sfEvtKeyPressed) {
			player_movement(rpg);
			player_rotation(rpg);
			change_scene(rpg);
		}
		if (rpg->scenes[rpg->curr_scene]->buttons != NULL)
			manage_button(rpg, rpg->scenes[rpg->curr_scene]->buttons, rpg->event);
	}
	return (SUCCESS);
}
