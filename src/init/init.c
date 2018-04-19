/*
** EPITECH PROJECT, 2017
** File Name : init.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "init.h"

int init(rpg_t *rpg)
{
	int status = 0;

	status = init_window(rpg);
	if (status != 0)
		return (status);
	status = init_event(rpg);
	if (status != 0)
		return (status);
	return (status);
}
