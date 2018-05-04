/*
** EPITECH PROJECT, 2017
** File Name : init_scene.h
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include <memory.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "init.h"
#include "parse.h"
#include "define.h"

int init_scenes(rpg_t *rpg)
{
	int status = SUCCESS;
	config_setting_t *setting;

	setting = config_setting_lookup(rpg->set, "scenes");
	if (setting == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->nb_scenes = config_setting_length(setting);
	rpg->scenes = malloc(sizeof(scene_t *) * (rpg->nb_scenes + 1));
	if (rpg->scenes == NULL)
		return (MALLOC_FAILED);
	for (int i = 0; i < rpg->nb_scenes; i++) {
		rpg->scenes[i] = malloc(sizeof(scene_t));
		if (rpg->scenes[i] == NULL)
			return (MALLOC_FAILED);
		status = fill_scene(rpg, setting, i);
		if (status != SUCCESS)
			return (status);
	}
	rpg->scenes[rpg->nb_scenes] = NULL;
	return (status);
}

int fill_scene(rpg_t *rpg, config_setting_t *scenes_setting, int index)
{
	int status;
	config_setting_t *scene_setting = config_setting_get_elem(
		scenes_setting, index);
	const char *str;

	status = init_buttons(rpg, &rpg->scenes[index]->buttons, scene_setting);
	if (status != SUCCESS)
		return (status);
	if (!config_setting_lookup_string(scene_setting, "map", &str)) {
		rpg->scenes[index]->map = NULL;
		return (SUCCESS);
	}
	status = init_map(rpg, &rpg->scenes[index]->map, str);
	rpg->scenes[index]->text = NULL;
	return (status);
}
