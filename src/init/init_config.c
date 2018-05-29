/*
** EPITECH PROJECT, 2017
** File Name : init_config.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "my.h"
#include "rpg.h"
#include "define.h"

int init_config(rpg_t *rpg)
{
	rpg->config = malloc(sizeof(config_t));
	config_init(rpg->config);
	if (config_read_file(rpg->config, "data/rpg.cfg") != CONFIG_TRUE)
		return (my_puterror(
			"In init_config: data/rpg.cfg: "), WRONG_PATH);
	rpg->set = config_lookup(rpg->config, "rpg");
	if (rpg->set == NULL)
		return (my_puterror("In init config: lookup rpg"),
		WRONG_CONFIG_PATH);
	return (SUCCESS);
}
