/*
** EPITECH PROJECT, 2017
** File Name : achievement.h
** File description:
** by Arthur Teisseire
*/

#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <SFML/Graphics.h>

typedef struct achievement_s {
	sfRectangleShape *rect;
	sfRectangleShape *icon;
	sfText *title;
	sfText *desc;
	sfText *xp;
} achievement_t;

#endif
