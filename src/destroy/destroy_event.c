/*
** EPITECH PROJECT, 2017
** File Name : destroy_event.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_event(sfEvent *event)
{
	free(event);
}
