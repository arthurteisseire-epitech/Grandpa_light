/*
** EPITECH PROJECT, 2017
** File Name : init_player.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "player.h"
#include "texture.h"
#include "define.h"
#include "init.h"
#include "tile.h"

int init_player(rpg_t *rpg)
{
	int status;
	config_setting_t *player_set = config_setting_lookup(rpg->set, "player");

	if (player_set == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->player = malloc(sizeof(player_t));
	if (rpg->player == NULL)
		return (MALLOC_FAILED);
	status = init_shape(&rpg->player->rect, player_set);
	if (status != SUCCESS)
		return (status);
	status = init_anims(rpg, &rpg->player->anim, player_set);
	if (status != SUCCESS)
		return (status);
	sfRectangleShape_setTexture(rpg->player->rect,
		rpg->player->anim[0]->texture, sfTrue);
	sfRectangleShape_setOrigin(rpg->player->rect, VEC_HALF_TILE);
	sfRectangleShape_setTextureRect(rpg->player->rect,
		rpg->player->anim[0]->rects[0]->rect);
	set_player_stat(rpg->player, player_set);
	return (status);
}

void set_player_stat(player_t *player, config_setting_t *this_set)
{
	player->pos = get_cfg_vec(this_set, "pos");
	player->curr_frame = 0;
	player->id_anim = 0;
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
