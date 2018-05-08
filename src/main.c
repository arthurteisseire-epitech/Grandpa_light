/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "init.h"
#include "states.h"
#include "destroy.h"
#include "define.h"

int main(void)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));

	CM(rpg);
	DR(init(rpg));
	if (rpg->musics != NULL)
		sfMusic_play(rpg->musics[0]);
	DR(game_loop(rpg));
	destroy(rpg);
	return (SUCCESS);
}
