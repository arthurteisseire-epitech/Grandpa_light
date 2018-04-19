/*
** EPITECH PROJECT, 2017
** File Name : states.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "states.h"

int states(rpg_t *rpg)
{
	int status = 0;

	status = event(rpg);
	if (status != 0)
		return (status);
	if (status != 0)
		status = update(rpg);
	if (status != 0)
		return (status);
	status = draw(rpg);
	return (status);
}
