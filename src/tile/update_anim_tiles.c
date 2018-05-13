/*
** EPITECH PROJECT, 2017
** File Name : update_anim_tiles.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "texture.h"
#include "tile.h"
#include "define.h"
#include "tool.h"

void update_anim_tiles(rpg_t *rpg, sfClock *clock)
{
	int i = 0;
	tile_t **tiles;
	static float delta_time = 0.0f;

	if (wait_delta_frame(clock, &delta_time, DELTA_FRAME) == FALSE)
		return;
	tiles = CURR_SCENE->anim_tiles;
	if (tiles == NULL)
		return;
	while (tiles[i] != NULL) {
		shift_texture_rect(tiles[i]->rect, tiles[i]->tx,
			&tiles[i]->curr_frame);
		i++;
	}
}
