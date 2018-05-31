/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <malloc.h>
#include <memory.h>
#include "my.h"
#include "vec.h"
#include "scene.h"
#include "tile.h"
#include "define.h"
#include "rpg.h"
#include "tool.h"

static sfVector2f get_direction(char dir)
{
	if (dir == LEFT)
		return ((sfVector2f){-1, 0});
	if (dir == RIGHT)
		return ((sfVector2f){1, 0});
	if (dir == UP)
		return ((sfVector2f){0, -1});
	if (dir == DOWN)
		return ((sfVector2f){0, 1});
	return ((sfVector2f){0, 0});
}

static char check_receptor_dir(sfVector2f pos1, sfVector2f pos2)
{
	return (pos1.x == -pos2.x || pos1.y == -pos2.y);
}

int action_laser(rpg_t *rpg, tile_t *laser)
{
	sfVector2f direction = get_direction(laser->direction);
	sfVector2f pos = add_vec(laser->pos, direction);
	char hor_laser = laser->direction == LEFT || laser->direction == RIGHT;
	char ver_laser = laser->direction == UP || laser->direction == DOWN;
	map_t *map = CURR_SCENE->map;

	laser->active = !laser->active;
	while (IN_MAP(pos, map) && MAP_TILE(map, pos)->laser_col == FALSE) {
		if (hor_laser)
			MAP_TILE(map, pos)->laser->horizontal = laser->active;
		if (ver_laser)
			MAP_TILE(map, pos)->laser->vertical = laser->active;
		pos = add_vec(pos, direction);
		if (IN_MAP(pos, map) && check_receptor_dir(
			get_direction(MAP_TILE(map, pos)->direction),
			direction) &&
			MAP_TILE(map, pos)->func == action_laser_captor)
			MAP_TILE(map, pos)->func(rpg, MAP_TILE(map, pos));
	}
	return (SUCCESS);
}

int *swap_lasers(rpg_t *rpg)
{
	int idx = 0;

	RPG_MAP(rpg)->active_lasers[0] = 0;
	for (tile_t *act_laser = get_next_tile(rpg, LAS_STR);
		act_laser != NULL; act_laser = get_next_tile(rpg, LAS_STR)) {
		if (act_laser->active) {
			action_laser(rpg, act_laser);
			RPG_MAP(rpg)->active_lasers[idx++] = 1;
		} else
			RPG_MAP(rpg)->active_lasers[idx++] = 0;
	}
	return (RPG_MAP(rpg)->active_lasers);
}

void swap_lasers_back(rpg_t *rpg)
{
	int idx = 0;

	for (tile_t *act_laser = get_next_tile(rpg, LAS_STR);
		act_laser != NULL; act_laser = get_next_tile(rpg, LAS_STR)) {
		if (RPG_MAP(rpg)->active_lasers[idx++] == 1)
			action_laser(rpg, act_laser);
	}
}
