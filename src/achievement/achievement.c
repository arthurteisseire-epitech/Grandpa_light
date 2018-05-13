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
#include "player.h"
#include "tool.h"

config_setting_t *find_setting_by_name(config_setting_t *array_set
	, const char *name)
{
	config_setting_t *elem = array_set;
	char const *str = NULL;
	int i = 0;

	while (elem != NULL) {
		elem = config_setting_get_elem(array_set, i);
		config_setting_lookup_string(elem, "name", &str);
		if (str && my_strcmp(str, name) == 0)
			return (elem);
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (elem);
}

static char const *get_xp_text(rpg_t *rpg, config_setting_t *parent)
{
	char *tmp;
	int xp = 0;
	char *xp_text = "XP: ";

	config_setting_lookup_int(parent, "xp", &xp);
	tmp = my_itoa(xp);
	if (xp > 0) {
		xp_text = concat(my_strdup(xp_text), "+", 1);
		xp_text = concat(xp_text, tmp, my_strlen(tmp));
	} else {
		xp_text = concat(my_strdup(xp_text), tmp, my_strlen(tmp));
	}
	if (xp_text == NULL)
		return (NULL);
	rpg->achievement->xp = xp;
	rpg->player->stats->xp += xp;
	free(tmp);
	return (xp_text);
}

static int set_strings(rpg_t *rpg, config_setting_t *parent, char const *name)
{
	char const *title = "This, is a great achievement\n";
	char const *desc = "Note: +1";
	char const *head = "New Achievement";
	char const *xp_text;
	config_setting_t *array_set;
	config_setting_t *elem_set;

	array_set = config_setting_lookup(parent, "array");
	CM(elem_set = find_setting_by_name(array_set, name));
	config_setting_lookup_string(parent, "xp_text", &xp_text);
	config_setting_lookup_string(elem_set, "title", &title);
	config_setting_lookup_string(elem_set, "desc", &desc);
	config_setting_lookup_string(elem_set, "head", &head);
	CM(xp_text = get_xp_text(rpg, elem_set));
	sfText_setString(rpg->achievement->title, title);
	sfText_setString(rpg->achievement->desc, desc);
	sfText_setString(rpg->achievement->xp_text, xp_text);
	sfText_setString(rpg->achievement->head, head);
	DR(set_texture_by_setting(rpg->tx_game, rpg->achievement->icon, elem_set));
	return (free((void *)xp_text), SUCCESS);
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
	rpg->achievement->nb_achieves++;
	return (SUCCESS);
}

void draw_achievement(rpg_t *rpg)
{
	static float delta_time = 0.0f;

	if (rpg->achievement == NULL)
		return;
	if (delta_time + DELTA_ACHIEVE >= sfTime_asSeconds(sfClock_getElapsedTime(rpg->clock))) {
		sfRenderWindow_drawRectangleShape(rpg->window
			, rpg->achievement->rect, NULL);
		sfRenderWindow_drawRectangleShape(rpg->window
			, rpg->achievement->icon, NULL);
		sfRenderWindow_drawText(rpg->window, rpg->achievement->title, NULL);
		sfRenderWindow_drawText(rpg->window, rpg->achievement->desc, NULL);
		sfRenderWindow_drawText(rpg->window, rpg->achievement->xp_text, NULL);
		sfRenderWindow_drawText(rpg->window, rpg->achievement->head, NULL);
	} else
		delta_time = sfTime_asSeconds(sfClock_getElapsedTime(rpg->clock));
}
