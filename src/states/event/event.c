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
#include "button.h"
#include "player.h"
#include "tile.h"
#include "tool.h"

void handle_exit_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		sfRenderWindow_close(rpg->window);
	}
}

int handle_pause_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		rpg->prev_scene = rpg->curr_scene;
		rpg->curr_scene = SC_PAUSE;
		return (1);
	}
	return (0);
}

static int handle_general_event(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (rpg->scenes[rpg->curr_scene]->buttons != NULL)
		manage_buttons(rpg, rpg->scenes[rpg->curr_scene]->buttons,
			rpg->event);
	return (SUCCESS);
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_general_event(rpg);
		if (rpg->scenes[rpg->curr_scene]->event != NULL)
			DR(rpg->scenes[rpg->curr_scene]->event(rpg));
		if (rpg->curr_scene == SC_PAUSE)
			break;
	}
	return (SUCCESS);
}
