/*
** EPITECH PROJECT, 2017
** File Name : particule.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARTICULE_H
#define PARTICULE_H

#include <SFML/Graphics.h>

typedef struct tile_s tile_t;

void laser_part(tile_t *tile, sfVertexArray *array, sfRectangleShape *rect);
void gen_particules(sfVertexArray *array, sfFloatRect rect, int nb, int *i);

#endif
