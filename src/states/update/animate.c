/*
** EPITECH PROJECT, 2017
** File Name : animate.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "character.h"
#include "vec.h"
#include "tile.h"

void set_player_pos(character_t *player)
{
	sfRectangleShape_setPosition(player->rect
		, mult_vec(player->pos, SIZE_TILE));
}
