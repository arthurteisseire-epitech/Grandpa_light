/*
** EPITECH PROJECT, 2017
** File Name : destroy_scene.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "destroy.h"
#include "tool.h"

void destroy_scene(scene_t *scene)
{
	if (scene->map != NULL)
		destroy_map(scene->map);
	if (scene->buttons != NULL)
		destroy_buttons(scene->buttons);
	free(scene->anim_tiles);
	free(scene);
}

void destroy_scenes(scene_t **scenes)
{
	int i = 0;

	if (scenes == NULL)
		return;
	while (scenes[i] != NULL) {
		destroy_scene(scenes[i]);
		i++;
	}
	free(scenes);
}
