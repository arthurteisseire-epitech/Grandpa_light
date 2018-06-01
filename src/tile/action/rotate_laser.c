/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "rpg.h"
#include "tile.h"
#include "player.h"

void rotate_sprite(tile_t *laser, float angle)
{
	sfRectangleShape_setRotation(laser->rect, angle);
}

void rotate(rpg_t *rpg, tile_t *laser, float angle, char dir)
{
	char was_active = laser->active;

	if (was_active)
		action_laser(rpg, laser);
	rotate_sprite(laser, angle);
	laser->direction = dir;
	if (was_active)
		action_laser(rpg, laser);
}

void rotate_laser(rpg_t *rpg, tile_t *laser)
{
	if (rpg->event->key.code == sfKeyUp)
		rotate(rpg, laser, DIR_UP, UP);
	if (rpg->event->key.code == sfKeyLeft)
		rotate(rpg, laser, DIR_LEFT, LEFT);
	if (rpg->event->key.code == sfKeyDown)
		rotate(rpg, laser, DIR_DOWN, DOWN);
	if (rpg->event->key.code == sfKeyRight)
		rotate(rpg, laser, DIR_RIGHT, RIGHT);
}
