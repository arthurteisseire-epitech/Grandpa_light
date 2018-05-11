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
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->window);
}

int handle_events(rpg_t *rpg)
{
	handle_exit_key(rpg); //deviendra handle pause
	if (rpg->event->type == sfEvtKeyPressed) {
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			player_event(rpg);
		change_scene(rpg);
	}
	return (SUCCESS);
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
		if (rpg->scenes[rpg->curr_scene]->scene_event != NULL)
			DR(rpg->scenes[rpg->curr_scene]->scene_event(rpg));
	}
	return (SUCCESS);
}
