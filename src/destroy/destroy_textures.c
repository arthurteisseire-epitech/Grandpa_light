/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "texture.h"

static void destroy_rects(rectangle_t **rects)
{
	int i = 0;

	while (rects[i] != NULL) {
		free(rects[i]);
		i++;
	}
	free(rects);
}

void destroy_textures(texture_t **textures)
{
	if (textures == NULL)
		return;
	for (unsigned int i = 0; textures[i] != NULL; i++) {
		destroy_rects(textures[i]->rects);
		sfTexture_destroy(textures[i]->texture);
		free(textures[i]);
	}
	free(textures);
}
