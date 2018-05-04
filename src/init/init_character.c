/*
** EPITECH PROJECT, 2017
** File Name : init_character.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "character.h"
#include "texture.h"
#include "define.h"
#include "init.h"

int init_character(rpg_t *rpg)
{
	int status;
	config_setting_t *char_setting = config_setting_lookup(rpg->set, "character");

	if (char_setting == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->character = malloc(sizeof(character_t));
	if (rpg->character == NULL)
		return (MALLOC_FAILED);
	status = init_shape(&rpg->character->rect, char_setting);
	if (status != SUCCESS)
		return (status);
	status = init_anims(rpg, &rpg->character->anim, char_setting);
	if (status != SUCCESS)
		return (status);
	sfRectangleShape_setTexture(rpg->character->rect,
		rpg->character->anim[0]->texture, sfTrue);
	sfRectangleShape_setTextureRect(rpg->character->rect,
		rpg->character->anim[0]->rects[0]->rect);
	rpg->character->pos = get_cfg_vec(char_setting, "pos");
	rpg->character->curr_frame = 0;
	return (status);
}

int init_anims(rpg_t *rpg, texture_t ***textures, config_setting_t *parent)
{
	int status;
	unsigned int nb_tx;
	config_setting_t *tx_set = config_setting_lookup(parent, "textures");

	if (tx_set == NULL)
		return (TEXTURE_NOT_FOUND);
	nb_tx = config_setting_length(tx_set);
	*textures = malloc(sizeof(texture_t *) * (nb_tx + 1));
	if (*textures == NULL)
		return (MALLOC_FAILED);
	for (unsigned int i = 0; i < nb_tx; i++) {
		status = init_anim(rpg, &(*textures)[i], tx_set, i);
		if (status != SUCCESS)
			return (status);
	}
	(*textures)[nb_tx] = NULL;
	return (SUCCESS);
}

int init_anim(rpg_t *rpg, texture_t **texture, config_setting_t *parent, int i)
{
	char const *str;
	config_setting_t *tx_set = config_setting_get_elem(parent, i);

	config_setting_lookup_string(tx_set, "name", &str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	*texture = get_texture_by_name(rpg->tx_game, str);
	return (SUCCESS);
}
