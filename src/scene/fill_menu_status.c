/*
** EPITECH PROJECT, 2017
** File Name : fill_menu_status.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "player.h"
#include "achievement.h"
#include "define.h"

int sfText_concat_int(sfText *text, int nb)
{
	const char *str;
	char *nb_str;

	nb_str = my_itoa(nb);
	CM(nb_str);
	str = sfText_getString(text);
	str = concat(my_strdup(str), nb_str, my_strlen(nb_str));
	CM(str);
	sfText_setString(text, str);
	free(nb_str);
	free((void *)str);
	return (SUCCESS);
}

int fill_menu_status(rpg_t *rpg)
{
	sfText_concat_int(rpg->scenes[SC_MENU_STATUS]->buttons[4]->text
	, rpg->player->stats->xp);
	sfText_concat_int(rpg->scenes[SC_MENU_STATUS]->buttons[5]->text
	, rpg->player->stats->level);
	sfText_concat_int(rpg->scenes[SC_MENU_STATUS]->buttons[6]->text
	, rpg->achievement->nb_achieves);
	return (SUCCESS);
}
