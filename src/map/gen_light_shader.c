/*
** EPITECH PROJECT, 2017
** File Name : gen_light_shader.c
** File description:
** Ozz
*/

#include <stdlib.h>
#include "define.h"
#include "tile.h"
#include "scene.h"
#include "vec.h"

void set_refresh(tile_t *tile)
{
	if (tile->lighted)
		//tile->light_level = MIN_BRIGHT;
		tile->light_level = NO_BRIGHT;
	else
		tile->light_level = NO_BRIGHT;
}

void refresh_light(map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			set_refresh(map->tiles[x][y]);
		}
	}
}

/*
static int init_light_map(float **light_map, sfVector2u size)
{
	(void)size;

	light_map = malloc(sizeof(float *) * (size.y + 1)); 
	for (unsigned int y = 0; y < size.y; y++) {
		light_map[y] = malloc(sizeof(float) * (size.x + 1));
		CM(light_map[y]);
		for (unsigned int x = 0; x < size.x; x++) {
			light_map[y][x] = MIN_BRIGHT;
		} 
		light_map[y][size.x] = -1;
	}
	light_map[size.y] = NULL;
	CM(light_map);
	return (SUCCESS);
}
*/

void player_light(map_t *map, sfVector2f pos, sfVector2f dir)
{
	gen_raycast(map, pos, dir);
}

void generate_shader(map_t *map, sfVector2f pos, sfVector2f dir)
{
	refresh_light(map);
	player_light(map, pos, dir);
	//torch_light(map);
}
