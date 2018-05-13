/*
** EPITECH PROJECT, 2017
** File Name : draw_laser_particule.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "tile.h"
#include "states.h"
#include "tool.h"


static void draw_laser_particules(rpg_t *rpg, sfVertexArray *array
, sfRectangleShape *rect)
{
	sfFloatRect r = sfRectangleShape_getLocalBounds(rect);
	sfFloatRect laser = {r.height + 10
	, r.left + 10, r.top + 10, r.width + 10};

	generate_particules(array, laser, 200);
	sfRenderWindow_drawVertexArray(rpg->window, rpg->vertex_array, NULL);
}

static tile_t *scan_map(rpg_t *rpg, tile_t **tiles, void *data)
{
	int i = 0;

	(void)data;
	while (tiles[i] != NULL) {
		if (tiles[i]->laser->horizontal)
			draw_laser_particules(rpg, rpg->vertex_array
			, tiles[i]->laser->hor_rect);
		if (tiles[i]->laser->vertical)
			draw_laser_particules(rpg
			, rpg->vertex_array, tiles[i]->laser->vert_rect);
		i++;
	}
	return (NULL);
}

void draw_laser_particule(rpg_t *rpg)
{
	apply_on_map(rpg, scan_map, NULL);
}
