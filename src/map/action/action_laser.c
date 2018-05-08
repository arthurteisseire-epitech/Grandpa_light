/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "vec.h"
#include "scene.h"
#include "tool.h"
#include "tile.h"
#include "define.h"
#include "rpg.h"

static sfVector2f get_direction(char dir)
{
	if (dir == LEFT)
		return ((sfVector2f){-1, 0});
	if (dir == RIGHT)
		return ((sfVector2f){1, 0});
	if (dir == UP)
		return ((sfVector2f){0, 1});
	if (dir == DOWN)
		return ((sfVector2f){0, -1});
	return ((sfVector2f){0, 0});
}

int action_laser(rpg_t *rpg, tile_t *laser)
{
	sfVector2f direction = get_direction(laser->direction);
	sfVector2f pos = add_vec(laser->pos, direction);
	char hor_laser = laser->direction == LEFT || laser->direction == RIGHT;
	char ver_laser = laser->direction == UP || laser->direction == DOWN;
	map_t *map = rpg->scenes[rpg->curr_scene]->map;

	laser->active = !laser->active;
	while (pos.x < map->size.x && pos.y < map->size.y &&
		map->tiles[(int)pos.x][(int)pos.y]->laser_col) {
		map->tiles[(int)pos.x][(int)pos.y]->laser->horizontal = (
			laser->active && hor_laser);
		map->tiles[(int)pos.x][(int)pos.y]->laser->vertical = (
			laser->active && ver_laser);
		pos = add_vec(pos, direction);
	}
	if (pos.x < map->size.x && pos.y < map->size.y && !my_strcmp(
		map->tiles[(int)pos.x][(int)pos.y]->name, "ls_receptor") &&
		map->tiles[(int)pos.x][(int)pos.y]->func != NULL)
		map->tiles[(int)pos.x][(int)pos.y]->func(rpg,
			map->tiles[(int)pos.x][(int)pos.y]);
	return (SUCCESS);
}