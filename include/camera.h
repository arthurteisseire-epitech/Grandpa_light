/*
** EPITECH PROJECT, 2017
** File Name : camera.h
** File description:
** by Arthur Teisseire
*/

#ifndef CAMERA_H
#define CAMERA_H

#ifndef GRAPH_H
#define GRAPH_H
	#include <SFML/Graphics.h>
#endif

typedef struct camera {
	sfVector2f *scale;
	sfVector2f *offset;
	sfVector2f *angle;
} camera_t;

#endif
