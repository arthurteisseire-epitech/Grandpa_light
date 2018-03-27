/*
** EPITECH PROJECT, 2017
** File Name : character.h
** File description:
** by Arthur Teisseire
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_ITEMS 1

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct object object_t;

typedef struct stat {
	int nb_photons;
	int damage;
	int hp;
} stat_t;

typedef struct inventory {
	object_t *items[MAX_ITEMS + 1];
} inventory_t;

typedef struct character {
	sfVector2i *pos;
	inventory_t *inventory;
	stat_t *stats;
} character_t;

#endif
