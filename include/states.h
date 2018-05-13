/*
** EPITECH PROJECT, 2017
** File Name : states.h
** File description:
** by Arthur Teisseire
*/

#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;
typedef struct button_s button_t;

int states(rpg_t *rpg);
int update(rpg_t *rpg);
int event(rpg_t *rpg);
int draw(rpg_t *rpg);

void draw_achievement(rpg_t *rpg);
void draw_on_achievement(rpg_t *rpg);
void draw_scene(rpg_t *rpg, scene_t *scene);
void draw_buttons(rpg_t *rpg, button_t **buttons);
void draw_player(rpg_t *rpg);
void draw_laser_particule(rpg_t *rpg);

#endif
