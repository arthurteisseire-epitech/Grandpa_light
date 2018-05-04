/*
** EPITECH PROJECT, 2017
** File Name : tool.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOL_H
#define TOOL_H

typedef struct map_s map_t;
typedef struct tile_s tile_t;

tile_t *get_line_tile(tile_t **tiles, char *name);
tile_t *get_map_tile(map_t *map, char *name);

#endif
