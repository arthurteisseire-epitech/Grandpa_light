/*
** EPITECH PROJECT, 2017
** File Name : update_particules.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "tool.h"

void update_particules(tile_t *tile, sfVertexArray *array, sfRectangleShape *rect)
{
	sfFloatRect r = sfRectangleShape_getGlobalBounds(rect);

	if (tile->laser->horizontal) {
		r.top -= RADIUS_LAS_PART / 2;
		r.height += RADIUS_LAS_PART;
		printf("hor\n");
	}
	if (tile->laser->vertical) {
		r.left -= RADIUS_LAS_PART / 2;
		r.width += RADIUS_LAS_PART;
		printf("ver\n");
	}
	generate_particules(array, r, NB_LAS_PART, &tile->laser->index_particule);
}
