/*
** EPITECH PROJECT, 2017
** File Name : destroy.h
** File description:
** by Arthur Teisseire
*/

#ifndef DESTROY_H
#define DESTROY_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <libconfig.h>

typedef struct rpg_s rpg_t;
typedef struct event_s event_t;
typedef struct scene_s scene_t;
typedef struct button_s button_t;
typedef struct texture_s texture_t;

void destroy(rpg_t *rpg);
void destroy_event(sfEvent *event);
void destroy_window(sfRenderWindow *window);
void destroy_scenes(scene_t **scenes);
void destroy_scene(scene_t *scene);
void destroy_buttons(button_t **buttons);
void destroy_clock(sfClock *clock);
void destroy_config(config_t *config);
void destroy_textures(texture_t **textures);
void destroy_musics(sfMusic **musics);

#endif
