/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "destroy.h"

void destroy(rpg_t *rpg)
{
	destroy_window(rpg->window);
	destroy_event(rpg->event);
	destroy_scenes(rpg->scenes);
	free(rpg);
}
