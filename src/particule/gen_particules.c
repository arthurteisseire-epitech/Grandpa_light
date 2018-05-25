/*
** EPITECH PROJECT, 2017
** File Name : gen_particules.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"
#include "tool.h"

sfVector2f get_random_pos(sfFloatRect rect)
{
	sfVector2f res;

	res.x = rand() % (int)rect.width + rect.left;
	res.y = rand() % (int)rect.height + rect.top;
	return (res);
}

void gen_particules(sfVertexArray *array, sfFloatRect rect, int nb, int *i)
{
	sfVector2f pos = get_random_pos(rect);
	sfVertex *tmp;
	sfVertex vertex = {.position = (sfVector2f){pos.x, pos.y}
	, .color = sfWhite};
	int nb_vertex = sfVertexArray_getVertexCount(array);

	for (int index = 0; index < nb_vertex; index++) {
		tmp = sfVertexArray_getVertex(array, index);
		tmp->color.a -= 2;
	}
	if (nb_vertex < nb)
		sfVertexArray_append(array, vertex);
	else {
		(*i) = (*i) + 1 >= nb_vertex ? 0 : (*i) + 1;
		tmp = sfVertexArray_getVertex(array, *i);
		*tmp = vertex;
	}
}
