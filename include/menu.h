/*
** EPITECH PROJECT, 2017
** File Name : menu.h
** File description:
** by Arthur Teisseire
*/

#ifndef MENU_H
#define MENU_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct texture texture_t;
typedef struct rpg rpg_t;

typedef struct button {
	sfRectangleShape *rect;
	sfVector2f offset;
	texture_t *texture;
	int (*function)(rpg_t *rpg);
} button_t;

typedef struct scene_menu {
	texture_t *background;
	button_t **buttons;
} scene_menu_t;

typedef struct menu {
	scene_menu_t *main;
	scene_menu_t *option;
	scene_menu_t *play;
} menu_t;

#endif
