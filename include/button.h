/*
** EPITECH PROJECT, 2017
** File Name : button.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>

#ifndef NB_FT_BUTTON
	#define NB_FT_BUTTON 10
#endif

typedef struct rpg_s rpg_t;
typedef struct sprite_s sprite_t;
typedef int (*button_func_t)(rpg_t *);

typedef struct ft_button_s {
	char *name;
	button_func_t button_func;
} ft_button_t;

typedef struct button_s {
	sfRectangleShape *rect;
	sfText *text;
	button_func_t button_func;
} button_t;

int button_play(rpg_t *rpg);
int button_setting(rpg_t *rpg);
int button_exit(rpg_t *rpg);
int update_text(rpg_t *rpg);
int button_return(rpg_t *rpg);
int button_pause(rpg_t *rpg);
int button_volume(rpg_t *rpg);
int button_size(rpg_t *rpg);

static const ft_button_t ft_buttons[] = {{"play", button_play},
	{"setting", button_setting}, {"exit", button_exit},
	{"return_menu", button_return},
	{"stop_pause", button_pause},
	{"volume", button_volume},
	{"size", button_size},
	{"update_text", update_text}, {"return_menu", button_return},
	{"stop_pause", button_pause}
};

	button_func_t
get_func_button(char const *ft);
int check_over(rpg_t *rpg, button_t *button, sfVector2i pos);
int check_click(rpg_t *rpg, button_t *button, sfVector2i pos);
int manage_buttons(rpg_t *rpg, button_t **button, sfEvent *event);

#endif
