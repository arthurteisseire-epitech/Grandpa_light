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
	static float delta_time = 0.0f;

	if (wait_delta_frame(clock, &delta_time) == FALSE)
		return;
	shift_texture_rect(player->rect, player->anim[player->id_anim]
	, &player->curr_frame);
}
