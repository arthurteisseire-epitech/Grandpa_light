/*
** EPITECH PROJECT, 2017
** File Name : draw_scene.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "window.h"
#include "tile.h"

void draw_tile(rpg_t *rpg, tile_t *tile)
{
	sfRenderWindow_drawSprite(rpg->win->window, tile->sprite, NULL);
}

void draw_map(rpg_t *rpg, map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			draw_tile(rpg, map->tiles[x][y]);
		}
	}
}

void draw_scene(rpg_t *rpg, scene_t *scene)
{
	draw_map(rpg, scene->map);
}
