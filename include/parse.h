/*
** EPITECH PROJECT, 2017
** File Name : parse.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARSE_H
#define PARSE_H

#include <SFML/Graphics.h>

#define DIMG(path) "assets/images"

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;
typedef struct map_s map_t;
typedef struct tile_s tile_t;
typedef struct texture_s texture_t;

int parse_image(map_t *map, texture_t **tx, sfImage *image);
int fill_map_row(map_t *map, texture_t **tx, sfImage *image, int row);

#endif
