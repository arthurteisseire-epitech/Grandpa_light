/*
** EPITECH PROJECT, 2017
** File Name : shift_texture_rect.c
** File description:
** by Arthur Teisseire
*/

#include "texture.h"
#include "tile.h"

void shift_texture_rect(sfRectangleShape *rect, texture_t *tx, int *index_rect)
{
	if (tx->rects[*index_rect + 1] == NULL)
		(*index_rect) = 0;
	else
		(*index_rect)++;
	sfRectangleShape_setTextureRect(rect
		, tx->rects[*index_rect]->rect);
}
