/*
** EPITECH PROJECT, 2017
** File Name : shift_texture_rect.c
** File description:
** by Arthur Teisseire
*/

#include "texture.h"
#include "tile.h"

void shift_texture_rect(sfRectangleShape *rect, texture_t *tx, int *curr_frame)
{
	if (tx->rects[*curr_frame + 1] == NULL)
		(*curr_frame) = 0;
	else
		(*curr_frame)++;
	sfRectangleShape_setTextureRect(rect, tx->rects[*curr_frame]->rect);
}
