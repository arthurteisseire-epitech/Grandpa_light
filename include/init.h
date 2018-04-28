/*
** EPITECH PROJECT, 2017
** File Name : init.h
** File description:
** by Arthur Teisseire
*/

#ifndef INIT_H
#define INIT_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;
typedef struct config_setting_t config_setting_t;

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);
int init_scenes(rpg_t *rpg);
int init_map(rpg_t *rpg, scene_t *scene, const char *path);
int init_textures(rpg_t *rpg);
int init_config(rpg_t *rpg);
int count_setting_elem(config_setting_t *setting);

#endif
