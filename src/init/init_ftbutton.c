/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** init ft button
*/

#include "rpg.h"
#include "button.h"
#include "my.h"

int draw_credit(rpg_t *rpg)
{
	rpg->curr_scene = 1;
	return (0);
}

int draw_scene_1(rpg_t *rpg)
{
	rpg->curr_scene = 2;
	return (0);
}

int draw_setting(rpg_t *rpg)
{
	rpg->curr_scene = 3;
	return (0);
}

button_func_t get_func_button(char const *ft)
{
	for (int i = 0; i != 2; i++)
		if (my_strcmp(ft, ft_buttons[i].name))
			return (ft_buttons[i].button_func);
	return (NULL);
}