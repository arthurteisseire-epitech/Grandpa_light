/*
** EPITECH PROJECT, 2017
** File Name : update_particules.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "tool.h"

#include <stdio.h>
void update_particules(tile_t *tile, sfVertexArray *array, sfRectangleShape *rect)
{
	sfFloatRect r = sfRectangleShape_getGlobalBounds(rect);

	generate_particules(array, r, 200, &tile->laser->index_particule);
}
