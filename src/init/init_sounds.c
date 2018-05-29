/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/Audio.h>
#include <malloc.h>
#include "rpg.h"
#include "init.h"
#include "libconfig.h"
#include "define.h"

int init_sounds(rpg_t *rpg)
{
	unsigned int nb_sounds;
	config_setting_t *sounds_set = config_setting_lookup(rpg->set
	, "sounds");

	if (sounds_set == NULL) {
		rpg->sounds = NULL;
		return (SUCCESS);
	}
	nb_sounds = config_setting_length(sounds_set);
	rpg->sounds = malloc(sizeof(sfSound **) * (nb_sounds + 1));
	for (unsigned int i = 0; i < nb_sounds; i++)
		DR(init_sound(&rpg->sounds[i], sounds_set, i));
	rpg->sounds[nb_sounds] = NULL;
	return (SUCCESS);
}

static int init_sound(sfSound **sound, config_setting_t *parent, int i)
{
	const char *str;
	int loop = 1;
	double vol = 1.0;
	config_setting_t *sound_set = config_setting_get_elem(parent, i);

	*sound = sfSound_create();
	if (*sound == NULL)
		return (SOUND_NOT_FOUND);
	config_setting_lookup_string(sound_set, "path", &str);
	if (str == NULL)
		return (my_puterror("init sound: lookup paths:"),
		WRONG_CONFIG_PATH);
	config_setting_lookup_float(sound_set, "volume", &vol);
	config_setting_lookup_int(sound_set, "loop", &loop);
	sfSound_setLoop(*sound, loop);
	sfSound_setVolume(*sound, (float)vol);
	return (SUCCESS);
}
