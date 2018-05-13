/*
** EPITECH PROJECT, 2017
** File Name : particule.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"
#include "tool.h"

sfVector2f get_random_pos(sfIntRect rect)
{
	sfVector2f res;

	res.x = rand() % rect.width + rect.left;
	res.y = rand() % rect.height + rect.top;
	return (res);
}

void generate_particules(sfVertexArray *array, int nb)
{
	sfIntRect rect = {10, 10, 200, 100};
	sfVector2f pos = get_random_pos(rect);
	sfVertex *tmp;
	sfVertex vertex = {.position = (sfVector2f){pos.x, pos.y}
	, .color = sfWhite};
	static int nb_vertex = 0;
	static int index = 0;

	for (int i = 0; i < nb_vertex; i++) {
		tmp = sfVertexArray_getVertex(array, i);
		tmp->color.a -= 2;
	}
	if (nb_vertex < nb)
		sfVertexArray_append(array, vertex);
	else {
		index = index + 1 > nb_vertex ? 0 : index + 1;
		tmp = sfVertexArray_getVertex(array, index);
		*tmp = vertex;
	}
	if (nb_vertex <= nb)
		nb_vertex++;
}

void draw_particules(rpg_t *rpg, sfVertexArray *array)
{
	generate_particules(array, 100);
	sfVertexArray_setPrimitiveType(array, sfLinesStrip);
	sfRenderWindow_drawVertexArray(rpg->window, array, NULL);
}
