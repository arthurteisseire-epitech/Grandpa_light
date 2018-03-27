/*
** EPITECH PROJECT, 2017
** File Name : object.h
** File description:
** by Arthur Teisseire
*/

#ifndef OBJECT_H
#define OBJECT_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct object {
	sprite_t *sprite;
	char *name;
	char active;
	int direction;
	int (*action)(rpg_t *, struct object *);
} object_t;

#endif
