/*
** EPITECH PROJECT, 2017
** File Name : text.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.h>

typedef struct text_s {
	char *str;
	sfVector2i pos;
	sfVector2i size;
	sfText *text;
	sfColor color;
} text_t;

#endif
