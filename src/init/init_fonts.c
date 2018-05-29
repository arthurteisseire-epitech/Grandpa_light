/*
** EPITECH PROJECT, 2017
** File Name : init_font.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "rpg.h"
#include "init.h"
#include "font.h"
#include "define.h"

int init_fonts(rpg_t *rpg)
{
	config_setting_t *font_set = config_setting_lookup(rpg->set, "font");
	unsigned int len;

	if (font_set == NULL)
		return (WRONG_CONFIG_PATH);
	len = config_setting_length(font_set);
	rpg->fonts = malloc(sizeof(font_t *) * (len + 1));
	fill_fonts(rpg->fonts, font_set, len);
	rpg->fonts[len] = NULL;
	return (0);
}

int fill_fonts(font_t **fonts, config_setting_t *parent, unsigned int len)
{
	config_setting_t *elem;

	for (unsigned int i = 0; i < len; i++) {
		elem = config_setting_get_elem(parent, i);
		fonts[i] = malloc(sizeof(font_t));
		CM(fonts[i]);
		DR(set_fonts(fonts[i], elem));
	}
	return (SUCCESS);
}

int set_fonts(font_t *font, config_setting_t *parent)
{
	char const *name = NULL;
	char const *path = NULL;

	if (!config_setting_lookup_string(parent, "name", &name))
		return (WRONG_CONFIG_PATH);
	if (!config_setting_lookup_string(parent, "path", &path))
		return (WRONG_CONFIG_PATH);
	font->name = name;
	font->font = sfFont_createFromFile(path);
	CM(font->font);
	return (SUCCESS);
}
