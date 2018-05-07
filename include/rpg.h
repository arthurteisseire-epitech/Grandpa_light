/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg.h
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define NB_SCENES 3
#define TITLE "rpg"

typedef struct scene_s scene_t;
typedef struct menu_s menu_t;
typedef struct texture_s texture_t;
typedef struct window_s window_t;
typedef struct event_s event_t;
typedef struct config_t config_t;
typedef struct config_setting_t config_setting_t;
typedef struct player_s player_t;

typedef struct rpg_s {
	sfEvent *event;
	sfRenderWindow *window;
	sfMusic **musics;
	scene_t **scenes;
	texture_t **tx_tile;
	texture_t **tx_game;
	sfClock *clock;
	int curr_scene;
	int nb_scenes;
	config_setting_t *set;
	player_t *player;
} rpg_t;

int game_loop(rpg_t *rpg);

#endif
