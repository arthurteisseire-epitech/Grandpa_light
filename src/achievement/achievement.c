/*
** EPITECH PROJECT, 2017
** File Name : show_achievement.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "achievement.h"
#include "texture.h"
#include "define.h"

config_setting_t *find_setting_by_name(config_setting_t *array_set
	, const char *name)
{
	config_setting_t *elem = array_set;
	char const *str;
	int i = 0;

	while (elem != NULL) {
		elem = config_setting_get_elem(array_set, i);
		config_setting_lookup_string(elem, "name", &str);
		if (my_strcmp(str, name) == 0)
			return (elem);
		i++;
	}
	return (elem);
}

static int set_strings(rpg_t *rpg, config_setting_t *parent, char const *name)
{
	char const *title = "This, is a great achievement\n";
	char const *desc = "Must: +1";
	char const *xp_text = "XP: ";
	char *tmp;
	int xp = 0;
	config_setting_t *array_set;
	config_setting_t *elem_set;

	array_set = config_setting_lookup(parent, "array");
	elem_set = find_setting_by_name(array_set, name);
	config_setting_lookup_string(parent, "xp_text", &xp_text);
	config_setting_lookup_string(elem_set, "title", &title);
	config_setting_lookup_string(elem_set, "desc", &desc);
	config_setting_lookup_int(elem_set, "xp", &xp);
	tmp = my_itoa(xp);
	if (xp > 0) {
		xp_text = concat(my_strdup(xp_text), "+", 1);
		xp_text = concat((char *)xp_text, tmp, my_strlen(tmp));
	} else {
		xp_text = concat(my_strdup(xp_text), tmp, my_strlen(tmp));
	}
	free(tmp);
	sfText_setString(rpg->achievement->title, title);
	sfText_setString(rpg->achievement->desc, desc);
	sfText_setString(rpg->achievement->xp_text, xp_text);
	DR(set_texture_by_setting(rpg->tx_game, rpg->achievement->icon, elem_set));
	free((void *)xp_text);
	return (SUCCESS);
}

int fill_achievement(rpg_t *rpg, char const *name)
{
	config_setting_t *achieves_set;

	achieves_set = config_setting_lookup(rpg->set, "achievements");
	DR(set_texture_by_setting(rpg->tx_game
			, rpg->achievement->rect, achieves_set));
	if (achieves_set == NULL)
		return (WRONG_CONFIG_PATH);
	set_strings(rpg, achieves_set, name);
	return (SUCCESS);
}

void draw_achievement(rpg_t *rpg)
{
	if (rpg->achievement == NULL)
		return;
	fill_achievement(rpg, "first_achievement");
	sfRenderWindow_drawRectangleShape(rpg->window
		, rpg->achievement->rect, NULL);
	sfRenderWindow_drawRectangleShape(rpg->window
		, rpg->achievement->icon, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->title, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->desc, NULL);
	sfRenderWindow_drawText(rpg->window, rpg->achievement->xp_text, NULL);
}
