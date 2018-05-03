/*
** EPITECH PROJECT, 2017
** File Name : move_player.c
** File description:
** Ozz
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include"character.h"
#include"tile.h"

void move_player(sfVector2f *pos, int dir)
{
	switch(dir) {
		case(DIR_UP):
			pos->y--;
			break;
		case(DIR_DOWN):
			pos->y++;
			break;
		case(DIR_LEFT):
			pos->x--;
			break;
		case(DIR_RIGHT):
			pos->x++;
			break;
		default:
			break;
	}
}
