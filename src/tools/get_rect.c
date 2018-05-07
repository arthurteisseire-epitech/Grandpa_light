/*
** EPITECH PROJECT, 2017
** File Name : get_rect.c
** File description:
** Ozz
*/

#include <stddef.h>
#include "texture.h"
#include "define.h"
#include "my.h"

rectangle_t *get_rect(texture_t *texture, char *name)
{
	int i = 0;

	while (texture->rects[i] != NULL) {
		if (my_strcmp(texture->rects[i]->name, name) == 0)
			return (texture->rects[i]);
		i++;
	}
	return (texture->rects[0]);
}
