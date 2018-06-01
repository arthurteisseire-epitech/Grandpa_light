/*
** EPITECH PROJECT, 2017
** File Name : light_shader.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "tile.h"
#include "scene.h"

sfUint8 map_color(float value)
{
	return (255 - (sfUint8)(value * 255));
}

void set_light(sfRectangleShape *light, float value, sfColor color)
{
	color.a = map_color(value);
	sfRectangleShape_setFillColor(light, color);
}

void update_shader(rpg_t *rpg, map_t *map)
{
	sfColor color = rpg->is_darkness ? sfBlack: sfWhite;

	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			set_light(map->tiles[x][y]->light
			, map->tiles[x][y]->light_level, color);
		}
	}
}
