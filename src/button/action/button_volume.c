/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** volume
*/

#include "rpg.h"
#include "define.h"
#include "scene.h"
#include "button.h"

int button_volume(rpg_t *rpg)
{
	float value = sfMusic_getVolume(rpg->musics[0]) ? 0.00 : 1.50;
	int i = 0;

	while (rpg->musics[i] != NULL) {
		sfMusic_setVolume(rpg->musics[i], value);
		i++;
	}
	if (value == 0.00)
		sfText_setString(rpg->scenes[SC_SETTINGS]->buttons[0]->text
		, "VOLUME: OFF");
	else
		sfText_setString(rpg->scenes[SC_SETTINGS]->buttons[0]->text
		, "VOLUME: ON");
	return (SUCCESS);
}
