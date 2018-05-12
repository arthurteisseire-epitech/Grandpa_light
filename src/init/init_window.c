/*
** EPITECH PROJECT, 2017
** File Name : init_window.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "define.h"

int init_window(rpg_t *rpg)
{
	sfVideoMode mode = {1920, 1080, 32};

	rpg->window = sfRenderWindow_create(
			mode, TITLE, sfResize | sfFullscreen | sfClose, NULL);
	CM(rpg->window);
	sfRenderWindow_setFramerateLimit(rpg->window, 60);
	return (SUCCESS);
}
