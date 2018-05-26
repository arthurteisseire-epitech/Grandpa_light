/*
** EPITECH PROJECT, 2017
** File Name : init_particule.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "particule.h"
#include "define.h"

int init_particule(particule_t **particule, sfColor color
, unsigned int nb_particules)
{
	*particule = malloc(sizeof(particule_t));
	CM(*particule);
	(*particule)->vertex_array = sfVertexArray_create();
	CM((*particule)->vertex_array);
	(*particule)->color = color;
	(*particule)->index_vertex = 0;
	(*particule)->nb_particules = nb_particules;
	(*particule)->rect = (sfFloatRect){0.0f, 0.0f, 0.0f, 0.0f};
	return (SUCCESS);
}
