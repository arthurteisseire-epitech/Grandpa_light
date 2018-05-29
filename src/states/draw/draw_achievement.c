/*
** EPITECH PROJECT, 2017
** File Name : draw_achieve.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "achievement.h"
#include "states.h"
#include "define.h"

void draw_on_achievement(rpg_t *rpg)
{
	static float delta_time = 0.0f;
	static float wait = 0.0f;
	sfTime time = sfClock_getElapsedTime(rpg->clock);

	if (rpg->achievement == NULL)
		return;
	if (rpg->is_achieve) {
		wait += DELTA_ACHIEVE;
		rpg->is_achieve = FALSE;
		delta_time = sfTime_asSeconds(time);
	}
	if (sfTime_asSeconds(time) <= delta_time + wait) {
		draw_achievement(rpg);
		return;
	}
	wait = 0.0f;
	rpg->is_achieve = FALSE;
}

void draw_achievement(rpg_t *rpg)
{
	sfRenderWindow_drawRectangleShape(rpg->window
		, rpg->achievement->rect, NULL);
	sfRenderWindow_drawRectangleShape(rpg->window
		, rpg->achievement->icon, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->title, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->desc, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->xp_text, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->head, NULL);
}
