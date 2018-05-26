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
#include "achievement.h"

void handle_exit_key(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		sfRenderWindow_close(rpg->window);
	}
}

int handle_pause_key(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyEscape &&
		rpg->event->type == sfEvtKeyReleased) {
		rpg->prev_scene = rpg->curr_scene;
		rpg->curr_scene = SC_PAUSE;
		new_achievement(rpg, "menu_pause");
		return (1);
	}
	return (0);
}

static int handle_general_event(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (CURR_SCENE->buttons != NULL)
		manage_buttons(rpg, CURR_SCENE->buttons,
			rpg->event);
	return (SUCCESS);
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_general_event(rpg);
		if (CURR_SCENE->event != NULL)
			DR(CURR_SCENE->event(rpg));
		if (rpg->curr_scene == SC_PAUSE)
			break;
	}
	return (SUCCESS);
}
