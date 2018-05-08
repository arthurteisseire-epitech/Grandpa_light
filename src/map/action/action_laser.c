/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Graphics.h>
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
	sfVector2i size = {map->size.x, map->size.y};

	laser->active = !laser->active;
	while (pos.x < size.x && pos.y < size.y) {
		map->tiles[(int)pos.x][(int)pos.y]->laser->horizontal =
			(laser->active && hor_laser);
		map->tiles[(int)pos.x][(int)pos.y]->laser->vertical =
			(laser->active && ver_laser);
		pos = add_vec(pos, direction);
	}
	return (SUCCESS);
}