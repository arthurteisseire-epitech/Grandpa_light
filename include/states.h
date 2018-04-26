/*
** EPITECH PROJECT, 2017
** File Name : states.h
** File description:
** by Arthur Teisseire
*/

#ifndef STATES_H
#define STATES_H

typedef struct rpg_s rpg_t;

int states(rpg_t *rpg);
int update(rpg_t *rpg);
int event(rpg_t *rpg);
int draw(rpg_t *rpg);

#endif