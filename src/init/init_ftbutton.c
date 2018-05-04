/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** init ft button
*/

#include "rpg.h"
#include "define.h"
#include "button.h"
#include "my.h"

int draw_credit(rpg_t *rpg)
{
	rpg->curr_scene = 1;
	return (SUCCESS);
}

int draw_scene_1(rpg_t *rpg)
{
	rpg->curr_scene = 2;
	return (SUCCESS);
}

int draw_setting(rpg_t *rpg)
{
	rpg->curr_scene = 3;
	return (SUCCESS);
}

button_func_t get_func_button(char const *ft)
{
	for (int i = 0; i != 2; i++)
		if (my_strcmp(ft, ft_buttons[i].name))
			return (ft_buttons[i].button_func);
	return (NULL);
}