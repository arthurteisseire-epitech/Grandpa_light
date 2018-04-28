/*
** EPITECH PROJECT, 2017
** File Name : init_buttons.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "rpg.h"
#include "texture.h"
#include "scene.h"
#include "button.h"
#include "init.h"
#include "define.h"

int init_buttons(rpg_t *rpg, scene_t *scene, config_setting_t *scene_setting)
{
	int status;
	unsigned int nb_buttons = config_setting_length(scene_setting);
	config_setting_t *buttons_setting = config_setting_lookup(scene_setting, "buttons");

	scene->buttons = malloc(sizeof(button_t) * (nb_buttons + 1));
	if (scene->buttons == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_buttons; i++) {
		scene->buttons[i] = malloc(sizeof(button_t));
		if (scene->buttons[i] == NULL)
			return (MALLOC_FAILED);
		status = init_button(rpg, scene->buttons[i], buttons_setting, i);
		if (status != SUCCESS)
			return (status);
	}
	return (SUCCESS);
}

int init_button(rpg_t *rpg, button_t *button, config_setting_t *buttons_setting, int i)
{
	config_setting_t *button_setting = config_setting_get_elem(buttons_setting, i);

	button->sprite = sfSprite_create();
	if (button->sprite == NULL)
		return (MALLOC_FAILED);
	sfSprite_setTexture(button->sprite, rpg->textures[0]->texture, sfTrue); //need texture index
	//need init_text with text_setting with button_setting
	return (SUCCESS);
}
