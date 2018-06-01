/*
** EPITECH PROJECT, 2017
** File Name : button_new_game.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "player.h"
#include "scene.h"
#include "define.h"

int button_new_game(rpg_t *rpg)
{
	rpg->prev_scene = SC_HUB;
	rpg->curr_scene = SC_HUB;
	if (CURR_SCENE->map != NULL)
		place_in_spawn(rpg);
	DR(reset_scenes(rpg));
	reset_player_stats(rpg->player);
	return (SUCCESS);
}
