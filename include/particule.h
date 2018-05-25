/*
** EPITECH PROJECT, 2017
** File Name : particule.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARTICULE_H
#define PARTICULE_H

#include <SFML/Graphics.h>

#define RADIUS_LAS_PART 6
#define NB_LAS_PART 200
#define NB_PLAYER_PART 60

typedef struct tile_s tile_t;
typedef struct player_s player_t;

void laser_part(tile_t *tile, sfVertexArray *array, sfRectangleShape *rect);
void gen_particules(sfVertexArray *array, sfFloatRect rect, int nb, int *i);
void player_part(player_t *player);

#endif
