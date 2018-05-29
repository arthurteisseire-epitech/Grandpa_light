/*
** EPITECH PROJECT, 2017
** File Name : light_shader.c
** File description:
** Ozz
*/

#include "tile.h"
#include "scene.h"

sfUint8 map_color(float value)
{
	return (255 - (sfUint8)(value * 255));
}

void set_light(sfRectangleShape *light, float value)
{
	sfColor color = sfBlack;

	color.a = map_color(value);
	sfRectangleShape_setFillColor(light, color);
}

void update_shader(map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			set_light(map->tiles[x][y]->light
			, map->tiles[x][y]->light_level);
		}
	}
}
