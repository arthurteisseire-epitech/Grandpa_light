/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Window.h>
#include "tool.h"
#include "rpg.h"
#include "event.h"
#include "scene.h"

int event_dialog(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtKeyPressed) {
		if (rpg->event->key.code == sfKeyReturn)
			rpg->curr_scene = SC_HUB;
		if (rpg->event->key.code == sfKeySpace)
			rpg->curr_scene = SC_HUB;
	}
	return (0);
}