/*
** EPITECH PROJECT, 2017
** File Name : reset_scenes.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "init.h"
#include "define.h"
#include "destroy.h"
#include "tile.h"

int reset_scenes(rpg_t *rpg)
{
	int i = 0;
	config_setting_t *scenes_set = config_setting_lookup(rpg->set
	, "scenes");
	config_setting_t *elem_set;

	while (rpg->scenes[i] != NULL) {
		elem_set = config_setting_get_elem(scenes_set, i);
		if (rpg->scenes[i]->map != NULL)
			DR(reset_scene(rpg, rpg->scenes[i], elem_set));
		i++;
	}
	return (SUCCESS);
}

int reset_scene(rpg_t *rpg, scene_t *scene, config_setting_t *scene_set)
{
	char const *save_path = NULL;
	char const *default_path = NULL;
	sfImage *image;

	if (!config_setting_lookup_string(scene_set, "save", &save_path)) {
		my_puterror("Need the save map to launch the new game\n");
		return (WRONG_CONFIG_PATH);
	}
	if (!config_setting_lookup_string(scene_set, "map", &default_path)) {
		my_puterror("Need the default map to launch the new game\n");
		return (WRONG_CONFIG_PATH);
	}
	image = sfImage_createFromFile(default_path);
	sfImage_saveToFile(image, save_path);
	sfImage_destroy(image);
	destroy_map(scene->map);
	free_and_set((void *)&scene->anim_tiles, NULL, free);
	init_map(rpg, &scene->map, save_path);
	generate_shader(CURR_SCENE->map, rpg->player);
	update_shader(CURR_SCENE->map);
	return (SUCCESS);
}
