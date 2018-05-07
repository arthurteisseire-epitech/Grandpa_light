/*
** EPITECH PROJECT, 2017
** File Name : animate.c
** File description:
** Ozz
*/

#include "rpg.h"
#include "texture.h"
#include "character.h"
#include "vec.h"
#include "tile.h"

void set_player_pos(character_t *player)
{
	sfRectangleShape_setPosition(player->rect
		, add_vec(scale_vec(player->pos, SIZE_TILE), VEC_HALF_TILE));
}

void animate_sprite(character_t *player, sfClock *clock)
{
	static float step = 0.1;
	sfTime time = sfClock_getElapsedTime(clock);

	if ((int)sfTime_asSeconds(time) < step)
		return;
	shift_texture_rect(player->rect, player->anim[player->id_anim]
	, &player->curr_frame);
	sfClock_restart(clock);
}
