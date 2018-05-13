/*
** EPITECH PROJECT, 2017
** File Name : inverse.c
** File description:
** by Arthur Teisseire
*/

#include "vec.h"

void inverse(unsigned int *a, unsigned int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

sfVector2f sub_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x - vec2.x, vec1.y - vec2.y});
}

