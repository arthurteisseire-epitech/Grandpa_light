/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#ifndef MY_RPG_DIALOG_H
#define MY_RPG_DIALOG_H

#include <SFML/Graphics/Types.h>

typedef struct dialog_s {
	sfRectangleShape *dialog_box;
	sfText *text;
	sfRectangleShape *player;
} dialog_t;

#endif //MY_RPG_DIALOG_H
