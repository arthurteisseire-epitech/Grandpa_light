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

int init(rpg_t *rpg);
int init_window(rpg_t *rpg);
int init_event(rpg_t *rpg);
int init_scenes(rpg_t *rpg);
int fill_scene(rpg_t *rpg, config_setting_t *scenes_setting, int index);
int init_button(rpg_t *rpg, button_t *button, config_setting_t *buttons_setting, int i);
int init_text(button_t *button, config_setting_t *button_setting, sfVector2f pos);
int init_buttons(rpg_t *rpg, scene_t *scene, config_setting_t *scene_setting);
int init_map(rpg_t *rpg, scene_t *scene, const char *path);
int init_textures(rpg_t *rpg);
int init_config(rpg_t *rpg);
int count_setting_elem(config_setting_t *setting);
sfVector2f get_cfg_pos(config_setting_t *pos);

#endif
