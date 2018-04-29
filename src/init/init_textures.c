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
	config_setting_t *parent = config_lookup(rpg->config, "rpg");
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
	const char *str;
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
		(*textures)[i] = malloc(sizeof(texture_t));
		if ((*textures)[i] == NULL)
			return (MALLOC_FAILED);
		tx_setting = config_setting_get_elem(textures_setting, i);
		config_setting_lookup_string(tx_setting, "path", &str);
		if (str == NULL)
			return (WRONG_CONFIG_PATH);
		(*textures)[i]->texture = sfTexture_createFromFile(str, NULL);
		if ((*textures)[i]->texture == NULL)
			return (WRONG_PATH);
		config_setting_lookup_string(tx_setting, "name", &(*textures)[i]->name);
		if ((*textures)[i]->name == NULL)
			return (WRONG_CONFIG_PATH);
		
	}
	(*textures)[nb_textures] = NULL;
	return (SUCCESS);
}

sfTexture *get_texture_by_name(texture_t **tx_game, char const *name)
{
	int i = 0;

	while (tx_game[i]) {
		if (my_strcmp(name, tx_game[i]->name) == 0)
			return (tx_game[i]->texture);
		i++;
	}
	return (NULL);
}

sfVector2f scale(sfSprite *sprite, sfVector2f new)
{
	const sfTexture *texture = sfSprite_getTexture(sprite);
	sfVector2u old = sfTexture_getSize(texture);
	sfVector2f scale;

	scale.x = old.x / new.x;
	scale.y = old.x / new.x;
	return (scale);
}
