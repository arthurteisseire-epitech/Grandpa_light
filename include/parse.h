/*
** EPITECH PROJECT, 2017
** File Name : parse.h
** File description:
** by Arthur Teisseire
*/

#ifndef PARSE_H
#define PARSE_H

#define DIMG(path) "assets/images"

typedef struct rpg_s rpg_t;
typedef struct scene_s scene_t;

int parse_image(scene_t *scene, char *path);

#endif
