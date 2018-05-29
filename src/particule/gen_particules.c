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
#include "particule.h"

sfVector2f get_random_pos(sfFloatRect rect)
{
	sfVector2f res;

	res.x = rand() % (int)rect.width + rect.left;
	res.y = rand() % (int)rect.height + rect.top;
	return (res);
}

void gen_particules(particule_t *particule)
{
	sfVector2f pos = get_random_pos(particule->rect);
	sfVertex *tmp;
	sfVertex vertex = {.position = (sfVector2f){pos.x, pos.y}
	, .color = particule->color};
	unsigned int nb_vertex = sfVertexArray_getVertexCount(
		particule->vertex_array);

	for (unsigned int index = 0; index < nb_vertex; index++) {
		tmp = sfVertexArray_getVertex(particule->vertex_array, index);
		tmp->color.a -= 2;
	}
	if (nb_vertex < particule->nb_particules)
		sfVertexArray_append(particule->vertex_array, vertex);
	else {
		particule->index_vertex = (particule->index_vertex + 1 >=
			nb_vertex) ? 0 : particule->index_vertex + 1;
		tmp = sfVertexArray_getVertex(particule->vertex_array
		, particule->index_vertex);
		*tmp = vertex;
	}
}
