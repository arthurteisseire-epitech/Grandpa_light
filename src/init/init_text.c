/*
** EPITECH PROJECT, 2017
** File Name : init_text.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "init.h"
#include "define.h"

int init_text(sfText **text, config_setting_t *parent)
{
	const char *str;
	sfFont *font;
	int size;
	config_setting_t *text_setting = config_setting_lookup(parent, "text");

	if (text_setting == NULL)
		return (WRONG_CONFIG_PATH);
	*text = sfText_create();
	if (!config_setting_lookup_string(text_setting, "str", &str))
		return (WRONG_CONFIG_PATH);
	sfText_setString(*text, str);
	if (!config_setting_lookup_string(text_setting, "font", &str))
		return (WRONG_CONFIG_PATH);
	font = sfFont_createFromFile(str);
	if (font == NULL)
		return (WRONG_PATH);
	sfText_setFont(*text, font);
	if (!config_setting_lookup_int(text_setting, "size", &size))
		return (WRONG_CONFIG_PATH);
	sfText_setCharacterSize(*text, size);
	sfText_setPosition(*text, get_cfg_pos(text_setting));
	return (SUCCESS);
}
