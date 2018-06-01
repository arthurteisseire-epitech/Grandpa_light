/*
** EPITECH PROJECT, 2017
** File Name : clean_particules.c
** File description:
** by Arthur Teisseire
*/

#include "particule.h"

void clean_particules(particule_t *particule)
{
	sfVertex *tmp;
	unsigned int nb_vertex = sfVertexArray_getVertexCount(
		particule->vertex_array);

	for (unsigned int index = 0; index < nb_vertex; index++) {
		tmp = sfVertexArray_getVertex(particule->vertex_array, index);
		tmp->color.a = 0;
		tmp->color.r = 0;
		tmp->color.g = 0;
		tmp->color.b = 0;
	}
}
