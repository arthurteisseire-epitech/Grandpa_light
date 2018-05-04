/*
** EPITECH PROJECT, 2017
** File Name : character.h
** File description:
** by Arthur Teisseire
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_ITEMS 1
#define DIR_UP 0
#define DIR_LEFT 1
#define DIR_DOWN 2
#define DIR_RIGHT 3

#include <SFML/Graphics/Types.h>
#include <SFML/System.h>

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
	sfVector2f pos;
	int curr_frame;
} character_t;

void move_player(sfVector2f *pos, int dir);
void set_player_pos(character_t *player);

#endif
