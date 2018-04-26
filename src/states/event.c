/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "camera.h"
#include "window.h"
#include "define.h"

static void handle_exit(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->win->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->win->window);
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->win->window, rpg->event)) {
		handle_exit(rpg);
	}
	return (SUCCESS);
}
