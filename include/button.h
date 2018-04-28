/*
** EPITECH PROJECT, 2017
** File Name : button.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Types.h>

typedef struct rpg_s rpg_t;

typedef struct button_s {
	sfSprite *sprite;
	sfText *text;
	int (*over)(rpg_t *, struct button_s *);
	int (*action)(rpg_t *, struct button_s *);
} button_t;

#endif
