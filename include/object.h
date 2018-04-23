/*
** EPITECH PROJECT, 2017
** File Name : object.h
** File description:
** by Arthur Teisseire
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.h>

#define NB_OBJ 1

typedef struct sprite_s sprite_t;
typedef struct rpg_s rpg_t;

typedef struct object_s {
	sprite_t *sprite;
	char *name;
	char active;
	int direction;
	int (*action)(rpg_t *, struct object_s *);
} object_t;

typedef struct obj_list_s {
	sfColor color;
	char *name;
} obj_list_t;

extern const obj_list_t obj_list[NB_OBJ];

#endif
