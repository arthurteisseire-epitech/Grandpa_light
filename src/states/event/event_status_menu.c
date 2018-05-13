/*
** EPITECH PROJECT, 2017
** File Name : event_status_menu.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "define.h"

int menu_status(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyO && rpg->event->type == sfEvtKeyReleased) {
		rpg->curr_scene = rpg->prev_scene;
	}
	return (SUCCESS);
}
