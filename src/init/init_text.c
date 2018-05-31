/*
** EPITECH PROJECT, 2017
** File Name : init_text.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "my.h"
#include "init.h"
#include "define.h"
#include "font.h"
#include "tool.h"

int init_text(sfText **text, config_setting_t *parent, font_t **fonts)
{
	config_setting_t *text_setting = config_setting_lookup(parent, "text");

	if (text_setting == NULL) {
		*text = NULL;
		return (SUCCESS);
	}
	*text = sfText_create();
	CM(*text);
	return (fill_text(*text, text_setting, fonts));
}

void is_black(sfText *text, config_setting_t *text_setting)
{
	const char *str = NULL;

	if (!config_setting_lookup_string(text_setting, "black", &str))
		return;
	sfText_setColor(text, sfBlack);
}

int fill_text(sfText *text, config_setting_t *text_setting, font_t **fonts)
{
	const char *str = NULL;
	font_t *font;
	int size = 10;

	if (!config_setting_lookup_string(text_setting, "str", &str))
		return (my_puterror("fill text: lookup str:"),
		WRONG_CONFIG_PATH);
	sfText_setString(text, str);
	if (!config_setting_lookup_string(text_setting, "font", &str))
		return (my_puterror("fill text: lookup font:")
		, WRONG_CONFIG_PATH);
	font = get_font_by_name(fonts, str);
	is_black(text, text_setting);
	if (font == NULL)
		return (my_puterror("In fill_text : font :"), WRONG_PATH);
	sfText_setFont(text, font->font);
	config_setting_lookup_int(text_setting, "size", &size);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, get_cfg_vec(text_setting, "pos"));
	return (SUCCESS);
}
