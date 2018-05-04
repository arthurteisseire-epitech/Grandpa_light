/*
** EPITECH PROJECT, 2017
** File Name : draw_scene.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "button.h"

void draw_tile(rpg_t *rpg, tile_t *tile)
{
	sfRenderWindow_drawSprite(rpg->window, tile->sprite, NULL);
	if (tile->laser->horizontal)
		sfRenderWindow_drawRectangleShape(rpg->window,
			tile->laser->hor_rect, NULL);
	if (tile->laser->vertical)
		sfRenderWindow_drawRectangleShape(rpg->window,
			tile->laser->vert_rect, NULL);
}

void draw_map(rpg_t *rpg, map_t *map)
{
	for (unsigned int x = 0; x < map->size.x; x++) {
		for (unsigned int y = 0; y < map->size.y; y++) {
			draw_tile(rpg, map->tiles[x][y]);
		}
	}
}

void draw_buttons(rpg_t *rpg, button_t **buttons)
{
	int i = 0;

	while (buttons[i]) {
		sfRenderWindow_drawRectangleShape(rpg->window, buttons[i]->rect,
			NULL);
		if (buttons[i]->text != NULL)
			sfRenderWindow_drawText(rpg->window, buttons[i]->text,
				NULL);
		i++;
	}
}

void draw_scene(rpg_t *rpg, scene_t *scene)
{
	if (scene->map != NULL)
		draw_map(rpg, scene->map);
	if (scene->buttons != NULL)
		draw_buttons(rpg, scene->buttons);
}
