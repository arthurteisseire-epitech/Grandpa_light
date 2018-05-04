/*
** EPITECH PROJECT, 2017
** File Name : vec.c
** File description:
** Ozz
*/

#include "vec.h"

sfVector2f mult_vec(sfVector2f vec1, int factor)
{
	return ((sfVector2f){vec1.x * factor, vec1.y * factor});
}

sfVector2f add_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x + vec2.x, vec1.y + vec2.y});
}
