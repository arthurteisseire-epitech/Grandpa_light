/*
** EPITECH PROJECT, 2017
** File Name : save_map.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "libconfig.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "define.h"

int save_scenes(rpg_t *rpg)
{
	int i = 0;
	config_setting_t *scenes_set = config_setting_lookup(rpg->set
	, "scenes");
	config_setting_t *elem_set;

	while (rpg->scenes[i] != NULL) {
		elem_set = config_setting_get_elem(scenes_set, i);
		DR(overwrite_map(rpg->scenes[i]->map, elem_set));
		i++;
	}
	return (SUCCESS);
}

int overwrite_map(map_t *map, config_setting_t *scene_set)
{
	char const *save_path = NULL;

	if (map == NULL)
		return (SUCCESS);
	config_setting_lookup_string(scene_set, "save", &save_path);
	save_map(map, save_path);
	return (SUCCESS);
}

int save_map(map_t *map, char const *save_path)
{
	sfColor color;
	sfImage *image = sfImage_createFromFile(save_path);

	if (image == NULL) {
		my_puterror("Save image not found\n");
		return (WRONG_PATH);
	}
	for (unsigned int row = 0; row < map->size.y; row++) {
		for (unsigned int col = 0; col < map->size.x; col++) {
			color = get_pixel_color(map, col, row);
			sfImage_setPixel(image, col, row, color);
		}
	}
	sfImage_saveToFile(image, save_path);
	sfImage_destroy(image);
	return (SUCCESS);
}

sfColor get_pixel_color(map_t *map, unsigned int row, unsigned int col)
{
	sfColor color = {0, 0, 0, 0};
	tile_t *tile = map->tiles[row][col];

	color.r |= (tile->active & 0b00000001);
	color.r |= (tile->direction & 0b00000110);
	color.g = (tile->chanel & 0x0f);
	color.b = tile_list[index_tile_by_name(tile->name)].color.b;
	return (color);
}
