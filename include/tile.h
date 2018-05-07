/*
** EPITECH PROJECT, 2017
** File Name : tile.h
** File description:
** by Arthur Teisseire
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.h>

#define MASK_NAME(color) ((color).b & 0x0f)
#define NB_TILE 8
#define SIZE_TILE 64
#define LASER_LENGTH 2
#define VEC_0_0 (sfVector2f){0.0, 0.0}
#define VEC_HALF_TILE (sfVector2f){(float)SIZE_TILE / 2, (float)SIZE_TILE / 2}

#define NO_BRIGHT 0.3
#define MIN_BRIGHT 0.8
#define LIGHT_POWER 0.25

typedef struct sprite_s sprite_t;
typedef struct rpg_s rpg_t;
typedef struct texture_s texture_t;
typedef struct map_s map_t;

typedef struct laser_s {
	char horizontal;
	char vertical;
	sfRectangleShape *vert_rect;
	sfRectangleShape *hor_rect;
} laser_t;

typedef struct tile_s {
	char *name;
	char active;
	char direction;
	char chanel;
	char player_col;
	char laser_col;
	char is_action;
	float light_level;
	char lighted;
	int (*func)(rpg_t *, struct tile_s *);
	laser_t *laser;
	sfRectangleShape *rect;
	sfRectangleShape *light;
	texture_t *tx;
	int index_rect;
	int curr_frame;
} tile_t;

typedef struct tile_list_s {
	sfColor color;
	char *name;
	char player_col;
	char laser_col;
	char is_action;
	int (*func)(rpg_t *, struct tile_s *);
	int idx_texture;
} tile_list_t;

typedef tile_t *(*get_tile_t)(rpg_t *, tile_t **, void *);
typedef int (*pos_tile_t)(map_t *, tile_t **, void *);

extern const tile_list_t tile_list[];

int index_tile_by_color(sfColor color);
void update_shader(map_t *map);
void generate_shader(map_t *map, sfVector2f pos, sfVector2f dir);
char is_in_map(map_t *map, sfVector2f pos);

tile_t *apply_on_map(rpg_t *rpg, get_tile_t func, void *data);
tile_t *get_tile_by_name(rpg_t *rpg, tile_t **tiles, void *name);
tile_t *set_tile_by_chanel(rpg_t *rpg, tile_t **tiles, void *data);
sfVector2f get_pos_tile_by_name(map_t *map, pos_tile_t func, void *name);
int tile_pos_line(map_t __attribute((unused))*map, tile_t **tiles, void *name);


int action_door(rpg_t __attribute((unused))*rpg, tile_t *tile);
int action_lever(rpg_t *rpg, tile_t *tile);

#endif
