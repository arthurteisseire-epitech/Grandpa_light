/*
** EPITECH PROJECT, 2017
** File Name : init_config.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "rpg.h"
#include "define.h"

int init_config(rpg_t *rpg)
{
	rpg->config = malloc(sizeof(config_t));
	if (rpg->config == NULL)
		return (MALLOC_FAILED);
	config_init(rpg->config);
	if (config_read_file(rpg->config, "data/rpg.cfg") != CONFIG_TRUE)
		return (WRONG_CONFIG_PATH);
	return (SUCCESS);
}

int count_setting_elem(config_setting_t *setting)
{
	const char *str = "";
	int i = 0;

	if (setting == NULL)
		return (0);
	while (str != NULL) {
		str = config_setting_get_string_elem(setting, i);
		i++;
	}
	return (i - 1);
}
