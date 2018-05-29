/*
** EPITECH PROJECT, 2017
** File Name : get_font_by_name.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "font.h"

font_t *get_font_by_name(font_t **fonts, char const *name)
{
	int i = 0;

	while (fonts[i] != NULL) {
		if (my_strcmp(fonts[i]->name, name) == 0)
			return (fonts[i]);
		i++;
	}
	return (NULL);
}
