/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Audio.h>
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "tool.h"
#include "my.h"

tile_t *find_tile_in_line(tile_t ***tiles, char *name, sfVector2u *pos,
	unsigned int size_y)
{
	while (pos->y < size_y) {
		if (my_strcmp(tiles[pos->x][pos->y]->name, name) == 0)
			return (tiles[pos->x][pos->y]);
		pos->y++;
	}
	return (NULL);
}

tile_t *get_next_tile(rpg_t *rpg, char *name)
{
	static tile_t ***tiles = NULL;
	static sfVector2u pos = {0, 0};
	tile_t *tile = NULL;

	if (tiles != rpg_tiles(rpg))
		pos = (sfVector2u){0, 0};
	tiles = rpg_tiles(rpg);
	while (pos.x < rpg_map(rpg)->size.x) {
		tile = find_tile_in_line(tiles, name, &pos,
			rpg_map(rpg)->size.y);
		if (tile != NULL) {
			pos.y++;
			return (tile);
		}
		pos.y = 0;
		pos.x++;
	}
	pos.x = 0;
	return (NULL);
}