/*
** EPITECH PROJECT, 2017
** File Name : save_game.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "player.h"
#include "scene.h"
#include "define.h"

int save_game(rpg_t *rpg)
{
	DR(save_player_stats(rpg->player));
	DR(save_scenes(rpg));
	return (SUCCESS);
}
