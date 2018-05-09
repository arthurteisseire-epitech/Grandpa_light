/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <malloc.h>
#include "tile.h"
#include "rpg.h"
#include "scene.h"
#include "define.h"

int *swap_lasers(rpg_t *rpg)
{
	int *active_list = malloc(sizeof(int) * MAX_LASER);
	int idx = 0;

	if (active_list == NULL)
		return (NULL);
	for (tile_t *act_laser = get_next_tile(rpg, LAS_STR);
		act_laser != NULL; act_laser = get_next_tile(rpg, LAS_STR)) {
		if (act_laser->active) {
			action_laser(rpg, act_laser);
			active_list[idx++] = 1;
		} else
			active_list[idx++] = 0;
	}
	return (active_list);
}

void swap_lasers_back(rpg_t *rpg, const int *active_list)
{
	int idx = 0;

	for (tile_t *act_laser = get_next_tile(rpg, LAS_STR);
		act_laser != NULL; act_laser = get_next_tile(rpg, LAS_STR))
		if (active_list[idx++] == 1)
			action_laser(rpg, act_laser);
}