/*
** EPITECH PROJECT, 2017
** File Name : destroy.h
** File description:
** by Arthur Teisseire
*/

#ifndef DESTROY_H
#define DESTROY_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <libconfig.h>

typedef struct rpg_s rpg_t;
typedef struct event_s event_t;
typedef struct scene_s scene_t;
typedef struct button_s button_t;
typedef struct texture_s texture_t;
typedef struct player_s player_t;
typedef struct tile_s tile_t;
typedef struct laser_s laser_t;
typedef struct map_s map_t;
typedef struct particule_s particule_t;
typedef struct achievement_s achievement_t;
typedef struct font_s font_t;

void destroy(rpg_t *rpg);
void destroy_event(sfEvent *event);
void destroy_window(sfRenderWindow *window);
void destroy_scenes(scene_t **scenes);
void destroy_scene(scene_t *scene);
void destroy_buttons(button_t **buttons);
void destroy_clock(sfClock *clock);
void destroy_config(config_t *config);
void destroy_textures(texture_t **textures);
void destroy_texts(sfText **text);
void destroy_musics(sfMusic **musics);
void destroy_player(player_t *player);
void destroy_tile(tile_t *tile);
void destroy_laser(laser_t *laser);
void destroy_map(map_t *map);
void destroy_raycast_circle(map_t *map);
void destroy_particule(particule_t *particule);
void destroy_achievement(achievement_t *achievement);
void destroy_anim_tiles(tile_t **tiles);
void destroy_fonts(font_t **fonts);

#endif
