/*
** EPITECH PROJECT, 2017
** File Name : init_scene.h
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
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
	config_setting_t *setting = config_lookup(rpg->config, "rpg.scenes.image");
	unsigned int nb_scenes = count_setting_elem(setting);
	const char *str;

	if (setting == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->scenes = malloc(sizeof(scene_t *) * (nb_scenes + 1));
	if (rpg->scenes == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_scenes; i++) {
		rpg->scenes[i] = malloc(sizeof(scene_t));
		if (rpg->scenes[i] == NULL)
			return (MALLOC_FAILED);
		str = config_setting_get_string_elem(setting, i);
		status = init_map(rpg, rpg->scenes[i], str);
		if (status != SUCCESS)
			return (status);
	}
	rpg->scenes[nb_scenes] = NULL;
	return (status);
}

int init_map(rpg_t *rpg, scene_t *scene, const char *path)
{
	map_t *map;
	sfImage *image = sfImage_createFromFile(path);
	
	if (image == NULL)
		return (WRONG_PATH);
	scene->map = malloc(sizeof(map_t));
	map = scene->map;
	map->size = sfImage_getSize(image);
	map->tiles = malloc(sizeof(tile_t **) * (scene->map->size.y + 1));
	if (scene->map == NULL)
		return (MALLOC_FAILED);
	for (unsigned int row = 0; row < map->size.y; row++) {
		map->tiles[row] = malloc(sizeof(tile_t *) * (map->size.x + 1));
		if (map->tiles[row] == NULL)
			return (MALLOC_FAILED);
		map->tiles[row][map->size.x] = NULL;
		if (parse_image_line(rpg, map, image, row) == -1)
			return (-1);
	}
	map->tiles[map->size.y] = NULL;
	return (SUCCESS);
}
