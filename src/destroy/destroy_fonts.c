/*
** EPITECH PROJECT, 2017
** File Name : destroy_fonts.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "font.h"

void destroy_fonts(font_t **fonts)
{
	int i = 0;

	if (fonts == NULL)
		return;
	while (fonts[i] != NULL) {
		sfFont_destroy(fonts[i]->font);
		free(fonts[i]);
		i++;
	}
	free(fonts);
}
