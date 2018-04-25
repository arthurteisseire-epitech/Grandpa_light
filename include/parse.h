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

int fill_map_row(map_t ***map, sfImage *image, sfVector2u size, int row);
int parse_image(scene_t *scene, sfImage *image, sfVector2u size);

#endif
