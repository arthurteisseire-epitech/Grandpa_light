/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "define.h"
#include "character.h"

int manage_button(rpg_t *rpg, button_t **button, sfEvent *event);

int update(rpg_t *rpg)
{
	set_player_pos(rpg->character);
	manage_button(rpg, rpg->scenes[rpg->curr_scene]->buttons, rpg->event);
	return (SUCCESS);
}