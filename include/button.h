/*
** EPITECH PROJECT, 2017
** File Name : button.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Types.h>

typedef struct rpg_s rpg_t;
typedef struct sprite_s sprite_t;
typedef int (*button_func_t)(rpg_t *);

typedef struct ft_button_s
{
	char *name;
	button_func_t button_func;
}ft_button_t;

int draw_credit(rpg_t *rpg);
int draw_scene_1(rpg_t *rpg);
int draw_setting(rpg_t *rpg);
button_func_t get_func_button(char const *ft);

static const ft_button_t ft_buttons[] = {
	{"play", draw_scene_1},
	{"setting", draw_setting},
	{"credit", draw_credit},
};

typedef struct button_s {
	sfRectangleShape *rect;
	sfText *text;
	button_func_t button_func;
} button_t;

#endif
