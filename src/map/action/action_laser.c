/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Audio.h>
#include "vec.h"
#include "scene.h"
#include "tool.h"
#include "tile.h"
#include "define.h"
#include "rpg.h"

static sfVector2i get_direction(char dir)
{
	if (dir == LEFT)
		return ((sfVector2i){-1, 0});
	if (dir == RIGHT)
		return ((sfVector2i){1, 0});
	if (dir == UP)
		return ((sfVector2i){0, 1});
	if (dir == DOWN)
		return ((sfVector2i){0, -1});
	return ((sfVector2i){0, 0});
}

int action_laser(rpg_t *rpg, tile_t *laser)
{

	sfVector2i direction = get_direction(laser->direction);
	sfVector2i pos = add_vec(laser->pos, direction);
	map_t *map = rpg->scenes[rpg->curr_scene]->map;
	sfVector2u size = {map->size.x, map->size.y};

	laser->active = !laser->active;
	while (pos.x < size.x && pos.y < size.y) {
		map->tiles[pos.x][pos.y]->laser->horizontal =
			(laser->direction == LEFT || laser->direction == RIGHT);
		map->tiles[pos.x][pos.y]->laser->vertical =
			(laser->direction == UP || laser->direction == DOWN);
	}
	return (SUCCESS);
}