/*
** EPITECH PROJECT, 2017
** File Name : vec.c
** File description:
** Ozz
*/

#include <libconfig.h>
#include "vec.h"

sfVector2f coord_mult(sfVector2f v1, sfVector2i v2)
{
	return ((sfVector2f){v1.x * v2.x, v1.y * v2.y});
}

sfVector2f scale_vec(sfVector2f vec1, int factor)
{
	return ((sfVector2f){vec1.x * factor, vec1.y * factor});
}

sfVector2f add_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x + vec2.x, vec1.y + vec2.y});
}

sfVector2f sub_vec(sfVector2f vec1, sfVector2f vec2)
{
	return ((sfVector2f){vec1.x - vec2.x, vec1.y - vec2.y});
}

sfVector2f get_cfg_vec(config_setting_t *parent, char const *name)
{
	double row;
	double col;
	config_setting_t *pos = config_setting_lookup(parent, name);

	if (pos == NULL || config_setting_length(pos) != 2)
		return ((sfVector2f){0, 0});
	row = config_setting_get_float_elem(pos, 0);
	col = config_setting_get_float_elem(pos, 1);
	return ((sfVector2f){(float)row, (float)col});
}
