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

void rotate_laser(rpg_t *rpg, tile_t *laser)
{
	if (rpg->event->key.code == sfKeyUp)
		rotate_sprite(laser, DIR_UP);
	if (rpg->event->key.code == sfKeyLeft)
		rotate_sprite(laser, DIR_LEFT);
	if (rpg->event->key.code == sfKeyDown)
		rotate_sprite(laser, DIR_DOWN);
	if (rpg->event->key.code == sfKeyRight)
		rotate_sprite(laser, DIR_RIGHT);
}