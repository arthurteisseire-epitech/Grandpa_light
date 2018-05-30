/*
** EPITECH PROJECT, 2017
** File Name : destroy_particule.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "particule.h"

void destroy_particule(particule_t *particule)
{
	if (particule == NULL)
		return;
	sfVertexArray_destroy(particule->vertex_array);
	free(particule);
}
