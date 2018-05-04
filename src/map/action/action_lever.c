/*
** EPITECH PROJECT, 2017
** File Name : action_lever.c
** File description:
** by Arthur Teisseire
*/

#include "scene.h"
#include "tile.h"
#include "define.h"

int action_lever(map_t *map, tile_t *tile)
{
	apply_on_map(map, set_tile_by_chanel, &tile->chanel);
	return (SUCCESS);
}
