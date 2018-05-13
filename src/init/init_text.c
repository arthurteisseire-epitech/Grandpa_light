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
	config_setting_t *text_setting = config_setting_lookup(parent, "text");

	if (text_setting == NULL) {
		*text = NULL;
		return (SUCCESS);
	}
	*text = sfText_create();
	CM(*text);
	return (fill_text(*text, text_setting));
}

int fill_text(sfText *text, config_setting_t *text_setting)
{
	const char *str;
	sfFont *font;
	int size = 10;

	if (!config_setting_lookup_string(text_setting, "str", &str))
		return (my_puterror("fill text: lookup str:"),
		WRONG_CONFIG_PATH);
	sfText_setString(text, str);
	if (!config_setting_lookup_string(text_setting, "font", &str))
		return (my_puterror("fill text: lookup font:"), WRONG_CONFIG_PATH);
	font = sfFont_createFromFile(str);
	if (font == NULL)
		return (my_puterror("In fill_text : font :"), WRONG_PATH);
	sfText_setFont(text, font);
	config_setting_lookup_int(text_setting, "size", &size);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, get_cfg_vec(text_setting, "pos"));
	return (SUCCESS);
}
