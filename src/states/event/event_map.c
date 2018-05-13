/*
** EPITECH PROJECT, 2017
** File Name : event_map.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "event.h"
#include "define.h"
#include "player.h"

int event_map(rpg_t *rpg)
{
	handle_exit_key(rpg); //deviendra handle pause
	set_inventory_text(rpg);
	if (rpg->event->type == sfEvtKeyPressed) {
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			player_event(rpg);
		launch_menu_status(rpg);
	}
	return (SUCCESS);
}

