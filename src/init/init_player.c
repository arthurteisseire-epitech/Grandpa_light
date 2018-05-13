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
	config_setting_t *player_set = config_setting_lookup(rpg->set,
		"player");

	if (player_set == NULL)
		return (my_puterror("lookup player: "), WRONG_CONFIG_PATH);
	rpg->player = malloc(sizeof(player_t));
	CM(rpg->player);
	DR(init_stats(&rpg->player->stats));
	DR(init_shape(&rpg->player->rect, player_set));
	DR(init_anims(rpg, &rpg->player->anim, player_set));
	DR(init_buttons(rpg, &rpg->player->items, player_set));
	sfRectangleShape_setTexture(rpg->player->rect,
		rpg->player->anim[0]->texture, sfTrue);
	sfRectangleShape_setOrigin(rpg->player->rect, VEC_HALF_TILE);
	sfRectangleShape_setTextureRect(rpg->player->rect,
		rpg->player->anim[0]->rects[0]->rect);
	set_player_stat(rpg->player, player_set);
	return (SUCCESS);
}

int init_stats(stat_t **stat)
{
	*stat = malloc(sizeof(stat_t));
		CM(*stat);
	(*stat)->level = 0;
	(*stat)->xp = 0;
	(*stat)->xp_to_up = 10;
	(*stat)->light_radius = RAYCAST_RADIUS;
	(*stat)->nb_orbe = 0;
	return (SUCCESS);
}

void set_player_stat(player_t *player, config_setting_t *this_set)
{
	player->pos = get_cfg_vec(this_set, "pos");
	player->curr_frame = 0;
	player->id_anim = 0;
}

int init_anims(rpg_t *rpg, texture_t ***textures, config_setting_t *parent)
{
	unsigned int nb_tx;
	config_setting_t *tx_set = config_setting_lookup(parent, "textures");

	if (tx_set == NULL)
		return (TEXTURE_NOT_FOUND);
	nb_tx = config_setting_length(tx_set);
	*textures = malloc(sizeof(texture_t *) * (nb_tx + 1));
		CM(*textures);
	for (unsigned int i = 0; i < nb_tx; i++)
		DR (init_anim(rpg, &(*textures)[i], tx_set, i));
	(*textures)[nb_tx] = NULL;
	return (SUCCESS);
}

int init_anim(rpg_t *rpg, texture_t **texture, config_setting_t *parent, int i)
{
	char const *str;
	config_setting_t *tx_set = config_setting_get_elem(parent, i);

	config_setting_lookup_string(tx_set, "name", &str);
	if (str == NULL)
		return (my_puterror(
			"init anim: lookup name: "), WRONG_CONFIG_PATH);
	*texture = get_texture_by_name(rpg->tx_game, str);
	return (SUCCESS);
}
