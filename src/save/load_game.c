/*
** EPITECH PROJECT, 2017
** File Name : load_game.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "player.h"
#include "scene.h"
#include "define.h"

int load_game(rpg_t *rpg)
{
	DR(load_player_stats(rpg->player));
	return (SUCCESS);
}
