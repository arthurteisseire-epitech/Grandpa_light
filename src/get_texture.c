/*
** EPITECH PROJECT, 2017
** File Name : get_texture.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Graphics.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "texture.h"
#include "define.h"

texture_t *get_texture_by_name(texture_t **textures, char const *name)
{
	int i = 0;

	while (textures[i]) {
		if (my_strcmp(name, textures[i]->name) == 0)
			return (textures[i]);
		i++;
	}
	return (NULL);
}

sfIntRect *get_texture_rect_by_name(texture_t *texture, char const *name)
{
	int i = 0;

	while (texture->rects[i]) {
		if (my_strcmp(name, texture->rects[i]->name) == 0)
			return (&texture->rects[i]->rect);
		i++;
	}
	return (NULL);
}

static void set_rectangle(sfRectangleShape *rect, texture_t *tx,
	sfIntRect *rect_int)
{
	sfRectangleShape_setTexture(rect, tx->texture, sfTrue);
	sfRectangleShape_setTextureRect(rect, *rect_int);
}

int set_texture_by_setting(texture_t **textures, sfRectangleShape *rect,
	config_setting_t *parent)
{
	char const *str;
	texture_t *tx;
	sfIntRect *rect_int;
	config_setting_t *tx_setting = config_setting_lookup(parent, "texture");

	if (tx_setting == NULL)
		return (WRONG_CONFIG_PATH);
	config_setting_lookup_string(tx_setting, "name", &str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	tx = get_texture_by_name(textures, str);
	if (tx == NULL)
		return (TEXTURE_NOT_FOUND);
	config_setting_lookup_string(tx_setting, "rect", &str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	rect_int = get_texture_rect_by_name(tx, str);
	if (rect_int == NULL)
		return (WRONG_CONFIG_PATH);
	set_rectangle(rect, tx, rect_int);
	return (SUCCESS);
}
