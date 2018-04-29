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
	unsigned int nb_buttons = config_setting_length(parent);
	config_setting_t *buttons_setting = config_setting_lookup(parent, "buttons");

	if (buttons_setting == NULL)
		return (WRONG_CONFIG_PATH);
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
	config_setting_t *button_setting = config_setting_get_elem(parent, i);
	int status;

	if (!config_setting_lookup_string(button_setting, "name", &button->name))
		return (WRONG_CONFIG_PATH);
	button->sprite = sfSprite_create();
	if (button->sprite == NULL)
		return (MALLOC_FAILED);
	sfSprite_setTexture(button->sprite, rpg->textures[5]->texture, sfTrue);
	sfSprite_setPosition(button->sprite, get_cfg_pos(button_setting));
	status = init_text(&button->text, button_setting);
	return (status);
}
