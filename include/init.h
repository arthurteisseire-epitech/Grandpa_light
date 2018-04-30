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

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);

int init_scenes(rpg_t *rpg);
int fill_scene(rpg_t *rpg, config_setting_t *parent, int index);

int init_button(rpg_t *rpg, button_t *button, config_setting_t *parent, int i);
int init_text(sfText **text, config_setting_t *parent);
int fill_text(sfText *text, config_setting_t *text_setting);
int init_buttons(rpg_t *rpg, button_t ***buttons, config_setting_t *parent);
int init_map(rpg_t *rpg, scene_t *scene, const char *path);

int init_textures(rpg_t *rpg);
int fill_textures(texture_t ***textures, config_setting_t *parent, const char *name);
int init_texture(texture_t **texture, config_setting_t *tx_setting);

int set_texture_rects(rectangle_t ***rects, config_setting_t *parent);
int set_texture_rect(rectangle_t *rect, config_setting_t *set, sfVector2f size, int i);
int init_config(rpg_t *rpg);

sfVector2f get_cfg_vec(config_setting_t *parent, char const *name);
sfVector2f scale(sfSprite *sprite, sfVector2f new);

#endif
