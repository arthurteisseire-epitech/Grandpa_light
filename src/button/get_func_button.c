/*
** EPITECH PROJECT, 2017
** File Name : get_func_button.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "button.h"

button_func_t get_func_button(char const *ft)
{
	for (int i = 0; i != 2; i++)
		if (my_strcmp(ft, ft_buttons[i].name) == 0)
			return (ft_buttons[i].button_func);
	return (NULL);
}
