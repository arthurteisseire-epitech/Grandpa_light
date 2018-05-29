/*
** EPITECH PROJECT, 2017
** File Name : destroy_achievement.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "achievement.h"

void destroy_achievement(achievement_t *achievement)
{
	sfRectangleShape_destroy(achievement->icon);
	sfRectangleShape_destroy(achievement->rect);
	sfText_destroy(achievement->desc);
	sfText_destroy(achievement->head);
	sfText_destroy(achievement->title);
	sfText_destroy(achievement->xp_text);
	free(achievement);
}
