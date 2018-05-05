/*
** EPITECH PROJECT, 2017
** File Name : gen_light_shader.c
** File description:
** Ozz
*/

#include "tile.h"
#include "scene.h"
#include "vec.h"

void set_refresh(tile_t *tile)
{
	if (tile->lighted)
		tile->light_level = MIN_BRIGH;
	else
		tile->light_level = NO_BRIGH;
}

void refresh_light(map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			set_refresh(map->tiles[x][y]);
		}
	}
}

void set_light_value(map_t *map, sfVector2f pos, float brightness)
{
	if (is_in_map(map, pos)) {
		if (brightness - LIGHT_POWER > MIN_BRIGH)
			map->tiles[(int)pos.x][(int)pos.y]->light_level 
				= brightness - LIGHT_POWER;
		map->tiles[(int)pos.x][(int)pos.y]->lighted = 1;
	}
}

void adj_tile_light(map_t *map, sfVector2f pos, float brightness, sfVector2f dir)
{
	map->tiles[(int)pos.x][(int)pos.y]->light_level = brightness;
	if (dir.x) {
		set_light_value(map, add_vec(pos, (sfVector2f){0.0, -1.0}), brightness);
		set_light_value(map, add_vec(pos, (sfVector2f){0.0, 1.0}), brightness);
	} else {
		set_light_value(map, add_vec(pos, (sfVector2f){-1.0, 0.0}), brightness);
		set_light_value(map, add_vec(pos, (sfVector2f){1.0, 0.0}), brightness);
	}
}

void generate_shader(map_t *map, sfVector2f pos, sfVector2f dir)
{
	float brightness = 1.0;	

	refresh_light(map);
	while (is_in_map(map, pos) && brightness > NO_BRIGH) {
		adj_tile_light(map, pos, brightness, dir);
		map->tiles[(int)pos.x][(int)pos.y]->lighted= 1;
		if (map->tiles[(int)pos.x][(int)pos.y]->laser_col)
			break;
		brightness -= LIGHT_POWER;
		pos = add_vec(pos, dir);
	}
}
