/*
** EPITECH PROJECT, 2017
** File Name : init_textures.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "texture.h"
#include "define.h"
#include "init.h"

int init_textures(rpg_t *rpg)
{
	config_setting_t *parent = rpg->set;
	int status;

	if (parent == NULL)
		return (WRONG_CONFIG_PATH);
	status = fill_textures(&rpg->tx_tile, parent, "tx_tile");
	if (status != SUCCESS)
		return (status);
	status = fill_textures(&rpg->tx_game, parent, "tx_game");
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}

int fill_textures(texture_t ***textures, config_setting_t *parent, const char *name)
{
	int status;
	unsigned int nb_textures;
	config_setting_t *textures_setting = config_setting_lookup(parent, name);
	config_setting_t *tx_setting;

	if (textures_setting == NULL)
		return (WRONG_CONFIG_PATH);
	nb_textures = config_setting_length(textures_setting);
	*textures = malloc(sizeof(texture_t **) * (nb_textures + 1));
	if (*textures == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_textures; i++) {
		tx_setting = config_setting_get_elem(textures_setting, i);
		status = init_texture(&(*textures)[i], tx_setting);
		if (status != SUCCESS)
			return (status);
	}
	(*textures)[nb_textures] = NULL;
	return (SUCCESS);
}

int init_texture(texture_t **texture, config_setting_t *tx_setting)
{
	char const *str;
	int status;

	(*texture) = malloc(sizeof(texture_t));
	if ((*texture) == NULL)
		return (MALLOC_FAILED);
	config_setting_lookup_string(tx_setting, "path", &str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	(*texture)->texture = sfTexture_createFromFile(str, NULL);
	if ((*texture)->texture == NULL)
		return (WRONG_PATH);
	config_setting_lookup_string(tx_setting, "name", &(*texture)->name);
	if ((*texture)->name == NULL)
		return (WRONG_CONFIG_PATH);
	status = set_texture_rects(&(*texture)->rects, tx_setting);
	return (status);
}

int set_texture_rects(rectangle_t ***rects, config_setting_t *parent)
{
	int status;
	unsigned int nb_rects;
	config_setting_t *names_setting = config_setting_lookup(parent, "names");
	sfVector2f size = get_cfg_vec(parent, "size");

	if (names_setting == NULL)
		return (WRONG_CONFIG_PATH);
	nb_rects = config_setting_length(names_setting);
	(*rects) = malloc(sizeof(rectangle_t *) * (nb_rects + 1));
	if (*rects == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_rects; i++) {
		(*rects)[i] = malloc(sizeof(rectangle_t));
		if ((*rects)[i] == NULL)
			return (MALLOC_FAILED);
		status = set_texture_rect((*rects)[i], names_setting, size, i);
		if (status != SUCCESS)
			return (status);
	}
	(*rects)[nb_rects] = NULL;
	return (SUCCESS);
}

int set_texture_rect(rectangle_t *rect, config_setting_t *set, sfVector2f size, int i)
{
	rect->name = config_setting_get_string_elem(set, i);
	if (rect->name == NULL)
		return (WRONG_CONFIG_PATH);
	rect->rect.width = size.x;
	rect->rect.height = size.y;
	rect->rect.left = i * size.x;
	rect->rect.top = 0;
	return (SUCCESS);
}
