/*
** EPITECH PROJECT, 2017
** File Name : destroy.h
** File description:
** by Arthur Teisseire
*/

#ifndef DESTROY_H
#define DESTROY_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct event_s event_t;
typedef struct scene_s scene_t;

void destroy(rpg_t *rpg);
void destroy_event(sfEvent *event);
void destroy_window(sfRenderWindow *window);
void destroy_scenes(scene_t **scenes);
void destroy_scene(scene_t *scene);

#endif
