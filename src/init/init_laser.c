/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <malloc.h>
#include "vec.h"
#include "tile.h"
#include "init.h"
#include "define.h"
#include "particule.h"

void set_laser(laser_t *laser, sfVector2f pos)
{
	sfVector2f tile_pos = scale_vec(pos, SIZE_TILE);
	sfVector2f horiz_pos = {tile_pos.x, tile_pos.y + SIZE_TILE / 2 - 1};
	sfVector2f vertical_pos = {tile_pos.x + SIZE_TILE / 2 + 2, tile_pos.y};
	sfVector2f laser_size = {SIZE_TILE, LASER_LENGTH};

	sfRectangleShape_setFillColor(laser->hor_rect, sfRed);
	sfRectangleShape_setFillColor(laser->vert_rect, sfRed);
	sfRectangleShape_setPosition(laser->vert_rect, vertical_pos);
	sfRectangleShape_setPosition(laser->hor_rect, horiz_pos);
	sfRectangleShape_setSize(laser->vert_rect, laser_size);
	sfRectangleShape_setSize(laser->hor_rect, laser_size);
	sfRectangleShape_rotate(laser->vert_rect, 90);
}

laser_t *init_laser(sfVector2f pos)
{
	laser_t *laser = malloc(sizeof(laser_t));

	if (laser == NULL)
		return (NULL);
	if (init_particule(&laser->particule
	, LASER_PART_COLOR, NB_LASER_PART) != SUCCESS)
		return (NULL);
	laser->vertical = 0;
	laser->horizontal = 0;
	laser->hor_rect = sfRectangleShape_create();
	laser->vert_rect = sfRectangleShape_create();
	if (laser->hor_rect == NULL || laser->vert_rect == NULL)
		return (NULL);
	set_laser(laser, pos);
	return (laser);
}
