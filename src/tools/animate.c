/*
** EPITECH PROJECT, 2017
** File Name : animate.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include "player.h"
#include "texture.h"
#include "define.h"

void animate_sprite(player_t *player, sfClock *clock)
{
	static float step = 0.1;
	sfTime time = sfClock_getElapsedTime(clock);

	if ((int)sfTime_asSeconds(time) < step)
		return;
	shift_texture_rect(player->rect, player->anim[player->id_anim]
	, &player->curr_frame);
	sfClock_restart(clock);
}
