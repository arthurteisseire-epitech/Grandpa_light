/*
** EPITECH PROJECT, 2017
** File Name : init_config.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "define.h"

int init_config(rpg_t *rpg)
{
	rpg->config = malloc(sizeof(config_t));
	if (rpg->config == NULL)
		return (MALLOC_FAILED);
	config_init(rpg->config);
	if (config_read_file(rpg->config, "data/rpg.cfg") != CONFIG_TRUE)
		return (WRONG_PATH);
	return (SUCCESS);
}

sfVector2f get_cfg_pos(config_setting_t *parent)
{
	double row;
	double col;
	config_setting_t *pos = config_setting_lookup(parent, "pos");

	if (pos == NULL || config_setting_length(pos) != 2)
		return ((sfVector2f){0, 0});
	row = config_setting_get_float_elem(pos, 0);
	col = config_setting_get_float_elem(pos, 1);
	return ((sfVector2f){row, col});
}
