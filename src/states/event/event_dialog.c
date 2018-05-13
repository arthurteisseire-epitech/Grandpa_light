/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Window.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "tool.h"
#include "define.h"

void dialog_continue(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeySpace ||
		rpg->event->key.code == sfKeyReturn)
		update_text(rpg);
}

void dialog_skip(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyEscape)
		rpg->curr_scene = SC_HUB;
}

int event_dialog(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtKeyPressed) {
		dialog_continue(rpg);
		dialog_skip(rpg);
	}
	return (SUCCESS);
}