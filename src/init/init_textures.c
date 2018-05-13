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

	if (parent == NULL)
		return (WRONG_CONFIG_PATH);
	DR(fill_textures(&rpg->tx_tile, parent, "tx_tile"));
	DR(fill_textures(&rpg->tx_game, parent, "tx_game"));
	return (SUCCESS);
}

int fill_textures(texture_t ***textures, config_setting_t *parent,
	const char *name)
{
	unsigned int nb_textures;
	config_setting_t *textures_setting = config_setting_lookup(parent,
		name);
	config_setting_t *tx_setting;

	if (textures_setting == NULL)
		return (WRONG_CONFIG_PATH);
	nb_textures = config_setting_length(textures_setting);
	*textures = malloc(sizeof(texture_t **) * (nb_textures + 1));
	CM(*textures);
	for (unsigned int i = 0; i < nb_textures; i++) {
		tx_setting = config_setting_get_elem(textures_setting, i);
		DR(init_texture(&(*textures)[i], tx_setting));
	}
	(*textures)[nb_textures] = NULL;
	return (SUCCESS);
}

int init_texture(texture_t **texture, config_setting_t *tx_setting)
{
	char const *str;

	(*texture) = malloc(sizeof(texture_t));
	CM(*texture);
	config_setting_lookup_string(tx_setting, "path", &str);
	if (str == NULL)
		return (my_puterror("In init_texture: path: "),
		WRONG_CONFIG_PATH);
	(*texture)->texture = sfTexture_createFromFile(str, NULL);
	if ((*texture)->texture == NULL)
		return (my_puterror("In init_texture: str: "), WRONG_PATH);
	config_setting_lookup_string(tx_setting, "name", &(*texture)->name);
	if ((*texture)->name == NULL)
		return (WRONG_CONFIG_PATH);
	DR(set_texture_rects(&(*texture)->rects, tx_setting));
	return (SUCCESS);
}

int set_texture_rects(rectangle_t ***rects, config_setting_t *parent)
{
	unsigned int nb_rects;
	config_setting_t *names_setting = config_setting_lookup(parent,
		"names");
	sfVector2f size = get_cfg_vec(parent, "size");

	if (names_setting == NULL)
		return (WRONG_CONFIG_PATH);
	nb_rects = config_setting_length(names_setting);
	*rects = malloc(sizeof(rectangle_t *) * (nb_rects + 1));
	CM(*rects);
	for (unsigned int i = 0; i < nb_rects; i++) {
		(*rects)[i] = malloc(sizeof(rectangle_t));
		CM((*rects)[i]);
		DR(set_texture_rect((*rects)[i], names_setting, size, i));
	}
	(*rects)[nb_rects] = NULL;
	return (SUCCESS);
}

int set_texture_rect(rectangle_t *rect, config_setting_t *set, sfVector2f size,
	int i)
{
	rect->name = config_setting_get_string_elem(set, i);
	if (rect->name == NULL)
		return (WRONG_CONFIG_PATH);
	rect->rect.width = (int)size.x;
	rect->rect.height = (int)size.y;
	rect->rect.left = (int)(i * size.x);
	rect->rect.top = 0;
	return (SUCCESS);
}
