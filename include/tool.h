/*
** EPITECH PROJECT, 2017
** File Name : tool.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOL_H
#define TOOL_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct tile_s tile_t;
typedef struct map_s map_t;
typedef struct button_s button_t;
typedef struct font_s font_t;
typedef struct config_setting_t config_setting_t;

#define ABS(x) (x < 0 ? -x : x)
#define RPG_MAP(rpg) ((rpg)->scenes[(rpg)->curr_scene]->map)
#define MAP_TILE(map, pos) ((map)->tiles[(int)((pos).x)][(int)((pos).y)])
#define RPG_TILES(rpg) ((rpg)->scenes[(rpg)->curr_scene]->map->tiles)
#define RPG_TILE(rpg, pos) ((rpg)->scenes[(rpg)->curr_scene]->map->\
tiles[(int)((pos).x)][(int)((pos).y)])
#define RPG_SCENE(rpg) ((rpg)->scenes[(rpg)->curr_scene])
#define IN_MAP(pos, map) (pos.x < map->size.x && pos.y < map->size.y && \
pos.x > 0 && pos.y > 0)

#define PI 3.14159265358979323846

int is_pos_in_rect(sfVector2i pos, sfFloatRect rect);
void inverse(unsigned int *a, unsigned int *b);
void set_rect(tile_t *tile);
void open_first_room(rpg_t *rpg);
int wait_delta_frame(sfClock *clock, float *delta_time, float delta_frame);
config_setting_t *find_setting_by_name(config_setting_t *array_set,
	const char *name);

int get_highest_active_chanel(map_t const *map);

char *get_next_dialog(int idx);
int update_text(rpg_t *rpg);
font_t *get_font_by_name(font_t **fonts, char const *name);

#endif
