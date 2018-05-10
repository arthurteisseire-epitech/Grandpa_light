/*
** EPITECH PROJECT, 2017
** File Name : init_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "tile.h"
#include "texture.h"
#include "scene.h"
#include "define.h"
#include "parse.h"
#include "tool.h"

static int init_row(rpg_t *rpg, map_t *map, sfImage *image, unsigned int row)
{
	map->tiles[row] = malloc(sizeof(tile_t *) * (map->size.x + 1));
	CM(map->tiles[row]);
	map->tiles[row][map->size.x] = NULL;
	DR(parse_image_line(rpg, map, image, row));
	return (SUCCESS);
}

static void open_door(tile_t *tile)
{
	if (my_strcmp(tile->name, "door") == 0 && tile->active) {
		tile->laser_col = 0;
		tile->player_col = 0;
		shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
	}
}

static void open_doors(tile_t ***tiles)
{
	int row = 0;
	int col;

	while (tiles[row] != NULL) {
		col = 0;
		while (tiles[row][col] != NULL) {
			open_door(tiles[row][col]);
			col++;
		}
		row++;
	}
}

static void init_lasers(map_t *map)
{
	for (unsigned int i = 0; i < MAX_LASER; i++)
		map->active_lasers[i] = 0;
}

int init_map(rpg_t *rpg, map_t **map, const char *path)
{
	sfImage *image = sfImage_createFromFile(path);

	if (image == NULL)
		return (my_puterror("In init_map : image : "), WRONG_PATH);
	(*map) = malloc(sizeof(map_t));
	CM(*map);
	(*map)->size = sfImage_getSize(image);
	inverse(&(*map)->size.x, &(*map)->size.y);
	(*map)->tiles = malloc(sizeof(tile_t **) * ((*map)->size.y + 1));
	CM((*map)->tiles);
	for (unsigned int row = 0; row < (*map)->size.y; row++)
		DR(init_row(rpg, *map, image, row));
	(*map)->tiles[(*map)->size.y] = NULL;
	inverse(&(*map)->size.x, &(*map)->size.y);
	open_doors((*map)->tiles);
	init_lasers((*map));
	return (SUCCESS);
}
