/*
** EPITECH PROJECT, 2017
** File Name : obj_list.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "tile.h"
#include "define.h"

const tile_list_t tile_list[NB_TILE] = {
	{{0x00, 0x00, 0x02, 0x00}, "wall", TRUE, TRUE, NULL}
};

int index_tile_by_color(sfColor color)
{
	for (int i = 0; i < NB_TILE; i++)
		if ((MASK_NAME(tile_list[i].color) & (MASK_NAME(color))) != 0)
			return (i);
	return (-1);
}
