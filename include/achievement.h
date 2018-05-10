/*
** EPITECH PROJECT, 2017
** File Name : achievement.h
** File description:
** by Arthur Teisseire
*/

#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <SFML/Graphics.h>

#define HEXA_COLOR(color_nb) ((sfColor) {				\
				(char)((color_nb >> 16) & 0xff),	\
				(char)((color_nb >> 8) & 0xff),		\
				(char)((color_nb) & 0xff),		\
				255})

typedef struct achievement_s {
	sfRectangleShape *rect;
	sfRectangleShape *icon;
	sfText *title;
	sfText *desc;
	sfText *xp_text;
	int xp;
} achievement_t;

#endif
