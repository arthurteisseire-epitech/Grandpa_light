/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** init ft button
*/

#include "rpg.h"
#include "button.h"
#include "my.h"

typedef int (*button_func_t)(rpg_t *);

typedef struct ft_button_s
{
	char *name;
	button_func_t button_func;
}ft_button_t;

static const ft_button_t ft_buttons[] = {
	{"play", draw_scene_1},
	{"setting", draw_setting}
	{"credit", draw_credit},
};

int draw_credit(rpg_t *rpg)
{
	rpg->curr_scene = 1;
}

int draw_scene_1(rpg_t *rpg)
{
	rpg->curr_scene = 2;
}

int draw_setting(rpg_t *rpg)
{
	rpg->curr_scene = 3;
}

button_func_t get_func_button(button_t *button, char *ft)
{
	for (int i = 0; i != 2; i++)
		if (my_strcmp(ft, ft_buttons[i].name))
			return (ft_buttons[i].button_func);
	return (NULL);
}