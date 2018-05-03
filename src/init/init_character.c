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
#include "define.h"
#include "init.h"

int init_character(rpg_t *rpg, config_setting_t *parent)
{
	int status;
	config_setting_t *char_setting = config_setting_lookup(parent, "character");

	if (char_setting == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->character = malloc(sizeof(character_t));
	if (rpg->character == NULL)
		return (MALLOC_FAILED);
	status = init_shape(rpg, &rpg->character->rect, char_setting);
	rpg->character->pos = get_cfg_vec(parent, "pos");
	rpg->character->curr_frame = 0;
	return (status);
}
