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

int init_buttons(rpg_t *rpg, scene_t *scene, config_setting_t *scene_setting)
{
	int status;
	unsigned int nb_buttons = config_setting_length(scene_setting);
	config_setting_t *buttons_setting = config_setting_lookup(scene_setting, "buttons");

	if (buttons_setting == NULL)
		return (WRONG_CONFIG_PATH);
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
	scene->buttons[nb_buttons] = NULL;
	return (SUCCESS);
}

int init_button(rpg_t *rpg, button_t *button, config_setting_t *buttons_setting, int i)
{
	config_setting_t *button_setting = config_setting_get_elem(buttons_setting, i);
	config_setting_t *pos_setting = config_setting_lookup(button_setting, "pos");
	sfVector2f pos;
	int status;

	if (pos_setting == NULL)
		return (WRONG_CONFIG_PATH);
	pos = get_cfg_pos(pos_setting);
	if (!config_setting_lookup_string(button_setting, "name", &button->name))
		return (WRONG_CONFIG_PATH);
	button->sprite = sfSprite_create();
	if (button->sprite == NULL)
		return (MALLOC_FAILED);
	sfSprite_setTexture(button->sprite, rpg->textures[5]->texture, sfTrue);
	sfSprite_setPosition(button->sprite, pos);
	status = init_text(button, button_setting, pos);
	return (status);
}

int init_text(button_t *button, config_setting_t *button_setting, sfVector2f pos)
{
	const char *str;
	sfFont *font;
	int size;
	config_setting_t *text_setting = config_setting_lookup(button_setting, "text");

	if (text_setting == NULL)
		return (WRONG_CONFIG_PATH);
	button->text = sfText_create();
	if (!config_setting_lookup_string(text_setting, "str", &str))
		return (WRONG_CONFIG_PATH);
	sfText_setString(button->text, str);
	if (!config_setting_lookup_string(text_setting, "font", &str))
		return (WRONG_CONFIG_PATH);
	font = sfFont_createFromFile(str);
	if (font == NULL)
		return (WRONG_PATH);
	sfText_setFont(button->text, font);
	if (!config_setting_lookup_int(text_setting, "size", &size))
		return (WRONG_CONFIG_PATH);
	sfText_setCharacterSize(button->text, size);
	sfText_setPosition(button->text, pos);
	return (SUCCESS);
}
