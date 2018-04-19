/*
** EPITECH PROJECT, 2017
** File Name : window.h
** File description:
** by Arthur Teisseire
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>

typedef struct window_s {
	int height;
	int width;
	sfRenderWindow *window;
} window_t;

#endif

