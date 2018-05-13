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
		if (update_text(RPG_SCENE(rpg)->buttons[DIAL_BOX_IDX]))
			rpg->curr_scene = SC_HUB;
}

void dialog_skip(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyEscape)
		rpg->curr_scene = SC_HUB;
}

int event_dialog(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtKeyPressed) {
		dialog_skip(rpg);
		dialog_continue(rpg);
	}
	return (SUCCESS);
}