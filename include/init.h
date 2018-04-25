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

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);
int init_scenes(rpg_t *rpg);
int init_map(scene_t *scene, char *path);
int init_tile(tile_t **tile, int index_tile);

#endif
