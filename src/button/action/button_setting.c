/*
** EPITECH PROJECT, 2017
** File Name : button_setting.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "define.h"

int button_setting(rpg_t *rpg)
{
	if (sfMusic_getVolume(rpg->musics[0]) == 0.00)
		sfText_setString(rpg->scenes[SC_SETTINGS]->buttons[0]->text,
			"VOLUME: OFF");
	else
		sfText_setString(rpg->scenes[SC_SETTINGS]->buttons[0]->text,
			"VOLUME: ON");
	rpg->curr_scene = SC_SETTINGS;
	return (SUCCESS);
}
