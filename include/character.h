/*
** EPITECH PROJECT, 2017
** File Name : character.h
** File description:
** by Arthur Teisseire
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_ITEMS 1

#include <SFML/Graphics/Types.h>

typedef struct object_s object_t;
typedef struct rpg_s rpg_t;

typedef struct stat_s {
	int nb_photons;
	int damage;
	int hp;
} stat_t;

typedef struct inventory_s {
	object_t *items[MAX_ITEMS + 1];
} inventory_t;

typedef struct character_s {
	sfRectangleShape *rect;
	inventory_t *inventory;
	stat_t *stats;
} character_t;

#endif
