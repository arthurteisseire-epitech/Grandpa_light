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

static void open_door(rpg_t *rpg, tile_t *tile)
{
	if ((tile->func == action_door || tile->func == action_room)
	&& tile->active) {
		tile->laser_col = 0;
		tile->player_col = 0;
		shift_texture_rect(tile->rect, tile->tx, &tile->curr_frame);
	} else if (tile->func == action_laser && tile->active) {
		tile->active = !tile->active;
		action_laser(rpg, tile);
		tile->active = !tile->active;
	}
}

static void open_doors(rpg_t *rpg, tile_t ***tiles)
{
	int row = 0;
	int col;

	while (tiles[row] != NULL) {
		col = 0;
		while (tiles[row][col] != NULL) {
			open_door(rpg, tiles[row][col]);
			col++;
		}
		row++;
	}
}

void init_lasers(rpg_t *rpg)
{
	tile_t *laser = get_next_tile(rpg, LAS_STR);
	int i = 0;

	while (laser != NULL) {
		RPG_MAP(rpg)->active_lasers[i] = laser->active;
		laser = get_next_tile(rpg, LAS_STR);
		i++;
	}
}

int init_map(rpg_t *rpg, map_t **map, const char *path)
{
	sfImage *image = sfImage_createFromFile(path);

	if (image == NULL)
		return (my_puterror("In init_map : image : "), WRONG_PATH);
	(*map) = malloc(sizeof(map_t));
	CM(*map);
	(*map)->size = sfImage_getSize(image);
	(*map)->raycast_circle = NULL;
	inverse(&(*map)->size.x, &(*map)->size.y);
	(*map)->tiles = malloc(sizeof(tile_t **) * ((*map)->size.y + 1));
	CM((*map)->tiles);
	for (unsigned int row = 0; row < (*map)->size.y; row++)
		DR(init_row(rpg, *map, image, row));
	(*map)->tiles[(*map)->size.y] = NULL;
	inverse(&(*map)->size.x, &(*map)->size.y);
	open_doors(rpg, (*map)->tiles);
	init_lasers(rpg);
	sfImage_destroy(image);
	return (SUCCESS);
}
