/*
** EPITECH PROJECT, 2017
** File Name : vec.c
** File description:
** Ozz
*/

#include "vec.h"

sfVector2f coord_mult(sfVector2f v1, sfVector2i v2)
{
	return ((sfVector2f){v1.x * v2.x, v1.y * v2.y});
}

sfVector2f scale_vec(sfVector2f vec1, int factor)
{
	return ((sfVector2f){vec1.x * factor, vec1.y * factor});
}

sfVector2f inv_scale_vec(sfVector2f vec1, int factor)
{
	return ((sfVector2f){vec1.x / factor, vec1.y / factor});
}

sfVector2f add_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x + vec2.x, vec1.y + vec2.y});
}

sfVector2f sub_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x - vec2.x, vec1.y - vec2.y});
}
