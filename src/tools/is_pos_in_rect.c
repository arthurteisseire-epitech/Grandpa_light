/*
** EPITECH PROJECT, 2017
** File Name : is_pos_in_rect.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include "define.h"

int is_pos_in_rect(sfVector2i pos, sfFloatRect rect)
{
	if (pos.x > rect.left && pos.x < rect.left + rect.width &&
	pos.y > rect.top && pos.y < rect.top + rect.height)
		return (TRUE);
	else
		return (FALSE);
}
