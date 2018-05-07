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
#include "player.h"

int update(rpg_t *rpg)
{
	set_player_pos(rpg->player);
	animate_sprite(rpg->player, rpg->clock);
	return (SUCCESS);
}
