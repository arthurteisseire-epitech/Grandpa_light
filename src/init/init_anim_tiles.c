/*
** EPITECH PROJECT, 2017
** File Name : init_anim_tiles.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "destroy.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "define.h"

static char *anim_names[] = {
	TORCH_STR,
	ORB_STR,
	NULL
};

int add_anim_tile(tile_t ***tiles, tile_t *tile)
{
	int i = 0;

	while (anim_names[i] != NULL) {
		if (my_strcmp(anim_names[i], tile->name) == 0) {
			*tiles = my_realloc((void **)*tiles, tile);
			return (*tiles == NULL ? MALLOC_FAILED : SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}

static void empty(void __attribute((unused))*a)
{
}

void rm_anim_tile(tile_t **tiles, tile_t *tile)
{
	int i = 0;

	if (tiles == NULL)
		return;
	while (tiles[i] != NULL) {
		if (tiles[i] == tile)
			break;
		i++;
	}
	rm_arrelem((void **)tiles, i, empty);
}
