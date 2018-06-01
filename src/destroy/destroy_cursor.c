/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** destroy cursor.c
*/

#include <stdlib.h>
#include "cursor.h"
#include "destroy.h"

void destroy_cursor(cursor_t *cursor)
{
	destroy_particule(cursor->particule);
	free(cursor);
}
