/*
** EPITECH PROJECT, 2018
** My_rpg
** File description:
** init cursor
*/

#include <stdlib.h>
#include "rpg.h"
#include "define.h"
#include "particule.h"
#include "init.h"
#include "cursor.h"

int init_cursor(rpg_t *rpg)
{
	rpg->cursor = malloc(sizeof(cursor_t));
	CM(rpg->cursor);
	DR(init_particule(&rpg->cursor->particule
	, PLAYER_PART_COLOR, NB_PLAYER_PART));
	return (0);
}