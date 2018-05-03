/*
** EPITECH PROJECT, 2017
** File Name : vec.c
** File description:
** Ozz
*/

#include "vec.h"

sfVector2f mult_vec(sfVector2f vec1, int factor)
{
	sfVector2f new_vec;

	new_vec.x = vec1.x * factor;
	new_vec.y = vec1.y * factor;
	return (new_vec);
}
