/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "camera.h"
#include "define.h"
#include "character.h"

static void handle_exit(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->window);
}

void player_movement(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyZ)
		move_player(&rpg->character->pos, DIR_UP);
	if (rpg->event->key.code == sfKeyQ)
		move_player(&rpg->character->pos, DIR_LEFT);
	if (rpg->event->key.code == sfKeyS)
		move_player(&rpg->character->pos, DIR_DOWN);
	if (rpg->event->key.code == sfKeyD)
		move_player(&rpg->character->pos, DIR_RIGHT);
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_exit(rpg);
		if (rpg->event->type == sfEvtKeyPressed)
			player_movement(rpg);
	}
	return (SUCCESS);
}
