/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event_pause.c
*/

#include <stdio.h>
#include "rpg.h"
#include "define.h"
#include "event.h"

int event_pause(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyEscape
	&& rpg->event->type == sfEvtKeyReleased)
		rpg->curr_scene = rpg->prev_scene;
	return (SUCCESS);
}
