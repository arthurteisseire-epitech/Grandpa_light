/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event for settings
*/

#include <stdio.h>
#include "rpg.h"
#include "define.h"
#include "event.h"
#include "scene.h"

int event_settings(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyEscape && rpg->event->type == sfEvtKeyReleased) {
		rpg->curr_scene = SCENE_MENU;
	}
	return (SUCCESS);
}
