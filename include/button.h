/*
** EPITECH PROJECT, 2017
** File Name : button.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>

typedef struct rpg_s rpg_t;
typedef struct sprite_s sprite_t;
typedef int (*button_func_t)(rpg_t *);

typedef struct ft_button_s
{
	char *name;
	button_func_t button_func;
}ft_button_t;

typedef struct button_s {
	sfRectangleShape *rect;
	sfText *text;
	button_func_t button_func;
} button_t;

int draw_credit(rpg_t *rpg);
int button_play(rpg_t *rpg);
int draw_setting(rpg_t *rpg);

static const ft_button_t ft_buttons[] = {
	{"play", button_play},
	{"setting", draw_setting},
	{"credit", draw_credit},
};

button_func_t get_func_button(char const *ft);
int check_over(rpg_t *rpg, button_t *button, sfVector2i pos);
int check_clic(rpg_t *rpg, button_t *button, sfVector2i pos);
int manage_buttons(rpg_t *rpg, button_t **button, sfEvent *event);

#endif
