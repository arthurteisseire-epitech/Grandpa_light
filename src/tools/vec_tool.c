/*
** EPITECH PROJECT, 2017
** File Name : vec_tool.c
** File description:
** Ozz
*/

#include "vec.h"
#include "tile.h"

sfVector2f get_direction(char dir)
{
	if (dir == LEFT)
		return ((sfVector2f){-1, 0});
	if (dir == RIGHT)
		return ((sfVector2f){1, 0});
	if (dir == UP)
		return ((sfVector2f){0, -1});
	if (dir == DOWN)
		return ((sfVector2f){0, 1});
	return ((sfVector2f){0, 0});
}
