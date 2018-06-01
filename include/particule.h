/*
** EPITECH PROJECT, 2017
** File Name : particule.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARTICULE_H
#define PARTICULE_H

#include <SFML/Graphics.h>

#define PLAYER_PART_COLOR ((sfColor){255, 255, 255, 255})
#define LASER_PART_COLOR ((sfColor){255, 0, 0, 255})
#define RADIUS_LAS_PART 6
#define NB_LASER_PART 200
#define NB_PLAYER_PART 40

typedef struct tile_s tile_t;
typedef struct player_s player_t;

typedef struct particule_s {
	sfVertexArray *vertex_array;
	sfFloatRect rect;
	sfColor color;
	unsigned int index_vertex;
	unsigned int nb_particules;
} particule_t;

void laser_part(tile_t *tile, sfRectangleShape *rect);
void gen_particules(particule_t *particule);
void clean_particules(particule_t *particule);
void player_part(player_t *player);

#endif
