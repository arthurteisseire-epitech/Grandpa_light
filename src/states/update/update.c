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

int update(rpg_t *rpg)
{
	if (rpg->scenes[rpg->curr_scene])
		manage_button(rpg, rpg->scenes[rpg->curr_scene]->buttons, rpg->event);
	animate_sprite(rpg->character, rpg->clock);
	return (SUCCESS);
}
