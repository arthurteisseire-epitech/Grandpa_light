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
	set_player_pos(rpg->character);
	animate_sprite(rpg->character, rpg->clock);
	return (SUCCESS);
}
