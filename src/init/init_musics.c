/*
** EPITECH PROJECT, 2017
** File Name : init_musics.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include "rpg.h"
#include "init.h"
#include "define.h"

int init_musics(rpg_t *rpg)
{
	int status;
	unsigned int nb_musics;
	config_setting_t *musics_set = config_setting_lookup(rpg->set, "musics");

	if (musics_set == NULL) {
		rpg->musics = NULL;
		return (SUCCESS);
	}
	nb_musics = config_setting_length(musics_set);
	rpg->musics = malloc(sizeof(sfMusic **) * (nb_musics + 1));
	for (unsigned int i = 0; i < nb_musics; i++) {
		status = init_music(&rpg->musics[i], musics_set, i);
		if (status != SUCCESS)
			return (status);
	}
	rpg->musics[nb_musics] = NULL;
	return (SUCCESS);
}

int init_music(sfMusic **music, config_setting_t *parent, int i)
{
	const char *str;
	double vol = 1.0;
	config_setting_t *music_set = config_setting_get_elem(parent, i);

	config_setting_lookup_string(music_set, "path", &str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	*music = sfMusic_createFromFile(str);
	if (*music == NULL)
		return (MUSIC_NOT_FOUND);
	config_setting_lookup_float(music_set, "volume", &vol);
	sfMusic_setVolume(*music, vol);
	return (SUCCESS);
}
