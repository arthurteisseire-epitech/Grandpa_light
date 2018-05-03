/*
** EPITECH PROJECT, 2017
** File Name : states.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "states.h"
#include "define.h"

int states(rpg_t *rpg)
{
	int status = SUCCESS;

	status = event(rpg);
	if (status != SUCCESS)
		return (status);
	status = update(rpg);
	if (status != SUCCESS)
		return (status);
	status = draw(rpg);
	if (status != SUCCESS)
		return (status);
	return (status);
}
