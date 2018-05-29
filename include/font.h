/*
** EPITECH PROJECT, 2017
** File Name : font.h
** File description:
** by Arthur Teisseire
*/

#ifndef FONT_H
#define FONT_H

#include <SFML/Graphics.h>

typedef struct font_s {
	char const *name;
	sfFont *font;
} font_t;

#endif
