/*
** EPITECH PROJECT, 2017
** File Name : fill_menu_status.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "player.h"
#include "achievement.h"
#include "tool.h"
#include "define.h"

static int get_str(rpg_t *rpg, const char **str, int index)
{
	config_setting_t *scene_set;
	config_setting_t *menu_status_set;
	config_setting_t *buttons_set;
	config_setting_t *elem;
	config_setting_t *text_set;

	scene_set = config_setting_lookup(rpg->set, "scenes");
	if (scene_set == NULL)
		return (WRONG_CONFIG_PATH);
	menu_status_set = find_setting_by_name(scene_set, "menu_status");
	buttons_set = config_setting_lookup(menu_status_set, "buttons");
	elem = config_setting_get_elem(buttons_set, index);
	text_set = config_setting_lookup(elem, "text");
	config_setting_lookup_string(text_set, "str", str);
	if (str == NULL)
		return (WRONG_CONFIG_PATH);
	return (SUCCESS);
}

int sfText_concat_int(rpg_t *rpg, sfText *text, int nb, int index)
{
	const char *str = NULL;
	char *nb_str;

		DR(get_str(rpg, &str, index));
	nb_str = my_itoa(nb);
		CM(nb_str);
	str = concat(my_strdup(str), nb_str, my_strlen(nb_str));
		CM(str);
	sfText_setString(text, str);
	free(nb_str);
	return (SUCCESS);
}

int fill_menu_status(rpg_t *rpg)
{
		DR(sfText_concat_int(rpg,
		rpg->scenes[SC_MENU_STATUS]->buttons[4]->text,
		rpg->player->stats->xp, 4));
		DR(sfText_concat_int(rpg,
		rpg->scenes[SC_MENU_STATUS]->buttons[5]->text,
		rpg->player->stats->level, 5));
		DR(sfText_concat_int(rpg,
		rpg->scenes[SC_MENU_STATUS]->buttons[6]->text,
		rpg->achievement->nb_achieves, 6));
	return (SUCCESS);
}

void launch_menu_status(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyO)) {
		fill_menu_status(rpg);
		rpg->curr_scene = SC_MENU_STATUS;
	}
}
