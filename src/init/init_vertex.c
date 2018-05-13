/*
** EPITECH PROJECT, 2017
** File Name : init_vertex.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "define.h"

int init_vertex(rpg_t *rpg)
{
	rpg->vertex_array = sfVertexArray_create();
	CM(rpg->vertex_array);
	return (SUCCESS);
}
