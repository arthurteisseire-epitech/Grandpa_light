/*
** EPITECH PROJECT, 2017
** File Name : init_scene.h
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <memory.h>
#include "rpg.h"
#include "scene.h"
#include "init.h"
#include "parse.h"
#include "define.h"

int init_scenes(rpg_t *rpg)
{
	int status = SUCCESS;

	rpg->scenes = malloc(sizeof(scene_t *) * (NB_SCENES + 1));
	if (rpg->scenes == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < NB_SCENES; i++) {
		rpg->scenes[i] = malloc(sizeof(scene_t));
		if (rpg->scenes[i] == NULL)
			return (MALLOC_FAILED);
		status = init_map(rpg->scenes[i], rpg->textures, "assets/images/lala.png");
		if (status != SUCCESS)
			return (status);
	}
	rpg->scenes[NB_SCENES] = NULL;
	return (status);
}

int init_map(scene_t *scene, texture_t **tx, char *path)
{
	sfImage *image = sfImage_createFromFile(path);
	
	if (image == NULL)
		return (WRONG_PATH);
	scene->size = sfImage_getSize(image);
	scene->map = malloc(sizeof(map_t **) * (scene->size.y + 1));
	if (scene->map == NULL)
		return (MALLOC_FAILED);
	scene->map[scene->size.y] = NULL;
	for (unsigned int row = 0; row < scene->size.y; row++) {
		scene->map[row] = malloc(sizeof(map_t *) * (scene->size.x + 1));
		if (scene->map[row] == NULL)
			return (MALLOC_FAILED);
		scene->map[row][scene->size.x] = NULL;
	}
	parse_image(scene, tx, image);
	return (SUCCESS);
}
