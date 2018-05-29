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
typedef struct button_s button_t;
typedef struct rectangle_s rectangle_t;
typedef struct config_t config_t;
typedef struct map_s map_t;
typedef struct player_s player_t;
typedef struct sfMusic sfMusic;
typedef struct laser_s laser_t;
typedef struct achievement_s achievement_t;
typedef struct stat_s stat_t;
typedef struct particule_s particule_t;
typedef struct font_s font_t;

typedef int (*init_arr_t)(rpg_t *);

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);
int init_musics(rpg_t *rpg);
int init_music(sfMusic **music, config_setting_t *parent, int i);
int init_player(rpg_t *rpg);
int init_stats(stat_t **stat);
int set_player_stat(player_t *player, config_setting_t *this_set);
int init_anims(rpg_t *rpg, texture_t ***textures, config_setting_t *parent);
int init_anim(rpg_t *rpg, texture_t **texture, config_setting_t *parent, int i);
int init_config(rpg_t *rpg);
int init_scenes(rpg_t *rpg);
int fill_scene(rpg_t *rpg, config_setting_t *parent, int index);
int fill_text(sfText *text, config_setting_t *text_setting, font_t **fonts);
int init_text(sfText **text, config_setting_t *parent, font_t **fonts);
int init_map(rpg_t *rpg, map_t **map, const char *path);
int init_tile(rpg_t *rpg, tile_t *tile, int index_tile, sfVector2f pos);
int init_buttons(rpg_t *rpg, button_t ***buttons, config_setting_t *parent);
int init_button(rpg_t *rpg, button_t **button, config_setting_t *parent, int i);
int init_shape(sfRectangleShape **rect, config_setting_t *parent);
int init_vertex(rpg_t *rpg);
int init_achievement(rpg_t *rpg);
laser_t *init_laser(sfVector2f pos);
int init_clock(sfClock ** clock);
int init_textures(rpg_t *rpg);
int fill_textures(texture_t ***textures, config_setting_t *parent,
	const char *name);
int init_texture(texture_t **texture, config_setting_t *tx_setting);
int set_texture_rects(rectangle_t ***rects, config_setting_t *parent);
int set_texture_rect(rectangle_t *rect, config_setting_t *set, sfVector2f size,
	int i);
int init_particule(particule_t **particule, sfColor color
, unsigned int nb_particules);
int init_fonts(rpg_t *rpg);
int fill_fonts(font_t **fonts, config_setting_t *parent, unsigned int len);
int set_fonts(font_t *font, config_setting_t *parent);

sfVector2f get_cfg_vec(config_setting_t *parent, char const *name);
sfVector2f scale(sfSprite *sprite, sfVector2f new);

#endif
