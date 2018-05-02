/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "texture.h"

void destroy_textures(texture_t **textures)
{
	for (unsigned int i = 0; textures[i] != NULL; i++) {
		free(textures[i]->rects);
		sfTexture_destroy(textures[i]->texture);
		free(textures[i]);
	}
	free(textures);
}