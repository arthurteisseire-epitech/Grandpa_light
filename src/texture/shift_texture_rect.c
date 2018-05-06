/*
** EPITECH PROJECT, 2017
** File Name : shift_texture_rect.c
** File description:
** by Arthur Teisseire
*/

#include "texture.h"
#include "tile.h"

void shift_texture_rect(texture_t **textures, tile_t *tile)
{
	texture_t *t = get_texture_by_name(textures, tile->name);

	if (t->rects[tile->index_rect + 1] == NULL)
		tile->index_rect = 0;
	else
		tile->index_rect++;
	sfRectangleShape_setTextureRect(tile->rect
		, t->rects[tile->index_rect]->rect);
}
