/*
** EPITECH PROJECT, 2017
** File Name : init_anim_tiles.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "scene.h"
#include "tile.h"
#include "define.h"

static char *anim_names[] = {
	"torch",
	NULL
};

int add_anim_tile(tile_t ***tiles, tile_t *tile)
{
	int i = 0;

	while (anim_names[i] != NULL) {
		if (my_strcmp(anim_names[i], tile->name) == 0) {
			*tiles = my_realloc((void **)*tiles, tile);
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}
