/*
** EPITECH PROJECT, 2017
** File Name : wait_frame_delta.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/System/Clock.h>
#include "texture.h"
#include "define.h"

int wait_delta_frame(sfClock *clock, float *delta_time, float delta_frame)
{
	sfTime time = sfClock_getElapsedTime(clock);

	if (sfTime_asSeconds(time) >= *delta_time + delta_frame) {
		*delta_time = sfTime_asSeconds(time);
		return (TRUE);
	}
	return (FALSE);
}
