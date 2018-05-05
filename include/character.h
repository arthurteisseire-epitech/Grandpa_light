/*
** EPITECH PROJECT, 2017
** File Name : character.h
** File description:
** by Arthur Teisseire
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_ITEMS 1
#define MOVE_UP (sfVector2f){0.0, -1.0}
#define MOVE_LEFT (sfVector2f){-1.0, 0.0}
#define MOVE_DOWN (sfVector2f){0.0, 1.0}
#define MOVE_RIGHT (sfVector2f){1.0, 0.0}
#define DIR_UP 270.0
#define DIR_LEFT 180.0
#define DIR_DOWN 90.0
#define DIR_RIGHT 0.0

#define ANIM_STAY 0
#define ANIM_MOVE 1

#include <SFML/Graphics/Types.h>
#include <SFML/System.h>

typedef struct object_s object_t;
typedef struct rpg_s rpg_t;
typedef struct texture_s texture_t;

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
	texture_t **anim;
	inventory_t *inventory;
	stat_t *stats;
	sfVector2f pos;
	int id_anim;
	int curr_frame;
} character_t;

void rotate_player(rpg_t *rpg, float angle, sfVector2f dir);
void move_player(rpg_t *rpg, sfVector2f *pos, sfVector2f move);
void set_player_pos(character_t *player);
void animate_sprite(character_t *player, sfClock *clock);

#endif
