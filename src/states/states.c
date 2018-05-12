/*
** EPITECH PROJECT, 2017
** File Name : states.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "states.h"
#include "define.h"
#include "scene.h"

int states(rpg_t *rpg)
{
	DR(event(rpg));
	DR(update(rpg));
	DR(draw(rpg));
	return (SUCCESS);
}