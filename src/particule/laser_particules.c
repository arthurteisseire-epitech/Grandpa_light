/*
** EPITECH PROJECT, 2017
** File Name : laser_particules.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "tool.h"
#include "particule.h"

void laser_part(tile_t *tile, sfVertexArray *array, sfRectangleShape *rect)
{
	sfFloatRect r = sfRectangleShape_getGlobalBounds(rect);

	if (tile->laser->horizontal) {
		r.top -= RADIUS_LAS_PART / 2;
		r.height += RADIUS_LAS_PART;
	}
	if (tile->laser->vertical) {
		r.left -= RADIUS_LAS_PART / 2;
		r.width += RADIUS_LAS_PART;
	}
	gen_particules(array, r, NB_LAS_PART, &tile->laser->index_particule);
}
