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

#define TITLE "rpg"

typedef struct scene_s scene_t;
typedef struct menu_s menu_t;
typedef struct texture_s texture_t;
typedef struct window_s window_t;
typedef struct event_s event_t;
typedef struct config_t config_t;
typedef struct config_setting_t config_setting_t;
typedef struct player_s player_t;
typedef struct achievement_s achievement_t;
typedef struct font_s font_t;
typedef struct cursor_s cursor_t;

typedef struct rpg_s {
	sfEvent *event;
	sfRenderWindow *window;
	sfVertexArray *vertex_array;
	sfMusic **musics;
	sfSound **sounds;
	scene_t **scenes;
	texture_t **tx_tile;
	texture_t **tx_game;
	sfClock *clock;
	int curr_scene;
	int prev_scene;
	int nb_scenes;
	config_setting_t *set;
	config_t *config;
	player_t *player;
	achievement_t *achievement;
	font_t **fonts;
	char is_achieve;
	cursor_t *cursor;
} rpg_t;

int game_loop(rpg_t *rpg);

#endif
