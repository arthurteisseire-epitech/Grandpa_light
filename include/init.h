/*
** EPITECH PROJECT, 2017
** File Name : init.h
** File description:
** by Arthur Teisseire
*/

#ifndef INIT_H
#define INIT_H

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);
int init_scenes(rpg_t *rpg);
int init_map(scene_t *scene, texture_t **tx, char *path);
int init_tile(tile_t **tile, texture_t **tx, int index_tile);

#endif
