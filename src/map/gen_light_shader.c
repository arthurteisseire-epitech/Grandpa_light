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
#include "player.h"
#include "vec.h"
#include "my.h"

void refresh_light(map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			map->tiles[x][y]->light_level = NO_BRIGHT;
		}
	}
}

light_t **get_torch(light_t **torchs, tile_t *tile)
{
	light_t *new_torch;

	if (!my_strcmp(tile->name, TORCH_STR) && tile->active) {
		new_torch = malloc(sizeof(light_t));
		new_torch->pos = tile->pos;
		new_torch->radius = TORCH_RADIUS;
		torchs = my_realloc((void **)torchs, new_torch);
	}
	return (torchs);
}

light_t **get_torchs(map_t *map)
{
	light_t **torchs = malloc(sizeof(light_t *));

	torchs[0] = NULL;
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			torchs = get_torch(torchs, map->tiles[x][y]);
		}
	}
	return (torchs);
}

void generate_shader(map_t *map, player_t *player)
{
	light_t **torchs = get_torchs(map);

	refresh_light(map);
	gen_raycast(map, player->pos, player->stats->light_radius);
	for (int i = 0; torchs[i] != NULL; i++) {
		gen_raycast(map, torchs[i]->pos, torchs[i]->radius);
		free(torchs[i]);
	}
	free(torchs);
}
