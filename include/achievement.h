/*
** EPITECH PROJECT, 2017
** File Name : achievement.h
** File description:
** by Arthur Teisseire
*/

#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct config_setting_t config_setting_t;

#define HEXA_TO_COLOR(color_nb) ((sfColor) {			\
				(((color_nb) >> 16) & 0xff),	\
				(((color_nb) >> 8) & 0xff),	\
				((color_nb) & 0xff),		\
				255})
#define DELTA_ACHIEVE 3.0f

typedef struct achievement_s {
	sfRectangleShape *rect;
	sfRectangleShape *icon;
	sfText *title;
	sfText *desc;
	sfText *xp_text;
	sfText *head;
	int xp;
	int nb_achieves;
} achievement_t;

void set_achievement_color(achievement_t *achievement
, config_setting_t *parent);
void set_achievement_pos(achievement_t *achieve
, config_setting_t *parent);
void set_achievement_size(achievement_t *achieve
, config_setting_t *parent);
int set_achievement_font(achievement_t *achieve
, config_setting_t *parent);
int new_achievement(rpg_t *rpg, char const *name);

#endif
