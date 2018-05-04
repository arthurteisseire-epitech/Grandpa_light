/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "camera.h"
#include "define.h"

static void handle_exit(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->window);
}

static void change_scene(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		rpg->curr_scene = (rpg->curr_scene + 1) % rpg->nb_scenes;
	else if (sfKeyboard_isKeyPressed(sfKeyLeft))
		rpg->curr_scene = (rpg->curr_scene == 0) ?
			rpg->nb_scenes - 1 : rpg->curr_scene - 1;
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_exit(rpg);
		change_scene(rpg);
	}
	return (SUCCESS);
}
