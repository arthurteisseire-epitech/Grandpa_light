/*
** EPITECH PROJECT, 2017
** File Name : init_textures.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "texture.h"
#include "define.h"

#define NB_TEXTURE 3

int init_textures(rpg_t *rpg)
{
	rpg->textures = malloc(sizeof(texture_t *) * (NB_TEXTURE + 1));
	if (rpg->textures == NULL)
		return (MALLOC_FAILED);
	for (int i = 0; i < NB_TEXTURE; i++) {
		rpg->textures[i] = malloc(sizeof(texture_t));
		if (rpg->textures[i] == NULL)
			return (MALLOC_FAILED);
	}
	rpg->textures[0]->texture = sfTexture_createFromFile(
			"assets/images/ground.png", NULL);
	rpg->textures[1]->texture = sfTexture_createFromFile(
			"assets/images/wall.png", NULL);
	rpg->textures[2]->texture = sfTexture_createFromFile(
			"assets/images/glass.png", NULL);
	rpg->textures[NB_TEXTURE] = NULL;
	return (SUCCESS);
}
