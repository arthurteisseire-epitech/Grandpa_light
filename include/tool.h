/*
** EPITECH PROJECT, 2017
** File Name : tool.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOL_H
#define TOOL_H

#include <SFML/Graphics.h>

int action_laser(rpg_t *rpg, tile_t *laser);
int is_pos_in_rect(sfVector2i pos, sfFloatRect rect);
void inverse(unsigned int *a, unsigned int *b);

#endif
