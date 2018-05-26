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

void laser_part(tile_t *tile, sfRectangleShape *rect)
{
	tile->laser->particule->rect = sfRectangleShape_getGlobalBounds(rect);
	if (tile->laser->horizontal) {
		tile->laser->particule->rect.top -= RADIUS_LAS_PART / 2;
		tile->laser->particule->rect.height += RADIUS_LAS_PART;
	}
	if (tile->laser->vertical) {
		tile->laser->particule->rect.left -= RADIUS_LAS_PART / 2;
		tile->laser->particule->rect.width += RADIUS_LAS_PART;
	}
	gen_particules(tile->laser->particule);
}
