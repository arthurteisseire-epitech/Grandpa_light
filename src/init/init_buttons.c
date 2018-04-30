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
	config_setting_t *buttons_setting = config_setting_lookup(parent, "buttons");

	if (buttons_setting == NULL)
		return (WRONG_CONFIG_PATH);
	nb_buttons = config_setting_length(buttons_setting);
	(*buttons) = malloc(sizeof(button_t) * (nb_buttons + 1));
	if (*buttons == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_buttons; i++) {
		(*buttons)[i] = malloc(sizeof(button_t));
		if ((*buttons)[i] == NULL)
			return (MALLOC_FAILED);
		status = init_button(rpg, (*buttons)[i], buttons_setting, i);
		if (status != SUCCESS)
			return (status);
	}
	(*buttons)[nb_buttons] = NULL;
	return (SUCCESS);
}

int init_button(rpg_t *rpg, button_t *button, config_setting_t *parent, int i)
{
	int status;
	const char *name;
	sfTexture *tx;
	double thick;
	config_setting_t *button_setting = config_setting_get_elem(parent, i);

	button->rect = sfRectangleShape_create();
	if (button->rect == NULL)
		return (MALLOC_FAILED);
	if (!config_setting_lookup_string(button_setting, "name", &name))
		return (WRONG_CONFIG_PATH);
	tx = get_texture_by_name(rpg->tx_game, name);
	if (tx == NULL)
		return (TEXTURE_NOT_FOUND);
	sfRectangleShape_setTexture(button->rect, tx, sfTrue);
	sfRectangleShape_setPosition(button->rect, get_cfg_vec(button_setting, "pos"));
	sfRectangleShape_setSize(button->rect, get_cfg_vec(button_setting, "size"));
	if (!config_setting_lookup_float(button_setting, "thick", &thick))
		return (WRONG_CONFIG_PATH);
	sfRectangleShape_setOutlineThickness(button->rect, thick);
	status = init_text(&button->text, button_setting);
	return (status);
}
