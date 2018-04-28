/*
** EPITECH PROJECT, 2017
** File Name : init_textures.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "texture.h"
#include "define.h"

static int count_textures(config_setting_t *setting)
{
	const char *str = "";
	int i = 0;

	while (str != NULL) {
		str = config_setting_get_string_elem(setting, i);
		i++;
	}
	return (i - 1);
}

int init_textures(rpg_t *rpg)
{
	config_setting_t *setting = config_lookup(rpg->config, "textures.texture");
	int nb_textures = count_textures(setting);
	const char *str;

	rpg->textures = malloc(sizeof(texture_t *) * (nb_textures + 1));
	if (rpg->textures == NULL)
		return (MALLOC_FAILED);
	for (int i = 0; i < nb_textures; i++) {
		rpg->textures[i] = malloc(sizeof(texture_t));
		if (rpg->textures[i] == NULL)
			return (MALLOC_FAILED);
		str = config_setting_get_string_elem(setting, i);
		rpg->textures[i]->texture = sfTexture_createFromFile(str, NULL);
		if (rpg->textures[i]->texture == NULL)
			return (WRONG_PATH);
	}
	rpg->textures[nb_textures] = NULL;
	config_setting_remove(setting, NULL);
	return (SUCCESS);
}
