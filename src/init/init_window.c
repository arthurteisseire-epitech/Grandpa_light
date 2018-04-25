/*
** EPITECH PROJECT, 2017
** File Name : init_window.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "window.h"
#include "define.h"

static int create_window(rpg_t *rpg)
{
	sfVideoMode mode = {rpg->win->width, rpg->win->height, 32};

	rpg->win->window = sfRenderWindow_create(
		mode, TITLE, sfResize | sfClose, NULL);
	if (rpg->win->window == NULL)
		return (MALLOC_FAILED);
	sfRenderWindow_setFramerateLimit(rpg->win->window, 60);
	return (SUCCESS);
}

int init_window(rpg_t *rpg)
{
	int status = SUCCESS;

	rpg->win = malloc(sizeof(window_t));
	if (rpg->win == NULL)
		return (MALLOC_FAILED);
	rpg->win->height = 1920;
	rpg->win->width = 1080;
	status = create_window(rpg);
	return (status);
}
