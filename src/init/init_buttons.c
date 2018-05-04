/*
** EPITECH PROJECT, 2017
** File Name : init_buttons.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "texture.h"
#include "scene.h"
#include "button.h"
#include "init.h"
#include "define.h"

int init_buttons(rpg_t *rpg, button_t ***buttons, config_setting_t *parent)
{
	int status;
	unsigned int nb_buttons;
	config_setting_t *buttons_set = config_setting_lookup(parent,
		"buttons");

	if (buttons_set == NULL) {
		*buttons = NULL;
		return (SUCCESS);
	}
	nb_buttons = config_setting_length(buttons_set);
	(*buttons) = malloc(sizeof(button_t) * (nb_buttons + 1));
	if (*buttons == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_buttons; i++) {
		(*buttons)[i] = malloc(sizeof(button_t));
		if ((*buttons)[i] == NULL)
			return (MALLOC_FAILED);
		status = init_button(rpg, (*buttons)[i], buttons_set, i);
		if (status != SUCCESS)
			return (status);
	}
	(*buttons)[nb_buttons] = NULL;
	return (SUCCESS);
}

int init_button(rpg_t *rpg, button_t *button, config_setting_t *parent, int i)
{
	int status;
	char const *ft_name = NULL;
	config_setting_t *button_set = config_setting_get_elem(parent, i);

	status = init_shape(&button->rect, button_set);
	if (status != SUCCESS)
		return (status);
	status = set_texture_by_setting(rpg->tx_game, button->rect, button_set);
	if (status != SUCCESS)
		return (status);
	config_setting_lookup_string(button_set, "function", &ft_name);
	button->button_func = get_func_button(ft_name);
	status = init_text(&button->text, button_set);
	return (status);
}
