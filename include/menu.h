/*
** EPITECH PROJECT, 2017
** File Name : menu.h
** File description:
** by Arthur Teisseire
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics/Types.h>

typedef struct texture_s texture_t;
typedef struct rpg_s rpg_t;
typedef struct button_s button_t;

typedef struct scene_menu_s {
	texture_t *background;
	button_t **buttons;
} scene_menu_t;

typedef struct menu_s {
	scene_menu_t *main;
	scene_menu_t *option;
	scene_menu_t *play;
} menu_t;

#endif
