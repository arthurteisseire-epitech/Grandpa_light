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
	update_xp(rpg, xp);
	free(tmp);
	return (xp_text);
}

static int is_achieve_done(config_setting_t *elem_set)
{
	int is_done = 1;

	config_setting_lookup_int(elem_set, "is_done", &is_done);
	if (is_done == TRUE)
		return (TRUE);
	return (FALSE);
}

static int set_strings(rpg_t *rpg, config_setting_t *parent, char const *name)
{
	char const *title = "This, is a great achievement\n";
	char const *desc = "Note: +1";
	char const *head = "New Achievement";
	char const *xp_text;
	config_setting_t *array_set = config_setting_lookup(parent, "array");
	config_setting_t *elem_set;

	CM(array_set);
	elem_set = find_setting_by_name(array_set, name);
	CM(elem_set);
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

static int fill_it(rpg_t *rpg, config_setting_t *parent, char const *name)
{
	config_setting_t *array_set = config_setting_lookup(parent, "array");
	config_setting_t *elem_set = find_setting_by_name(array_set, name);
	config_setting_t *is_done_set;

	CM(elem_set);
	if (!is_achieve_done(elem_set)) {
		set_strings(rpg, parent, name);
		rpg->achievement->nb_achieves++;
		rpg->is_achieve = TRUE;
		is_done_set = config_setting_lookup(elem_set, "is_done");
		CM(is_done_set);
		config_setting_set_int(is_done_set, 1);
	}
	return (SUCCESS);
}

int new_achievement(rpg_t *rpg, char const *name)
{
	config_setting_t *achieves_set;

	achieves_set = config_setting_lookup(rpg->set, "achievements");
	if (achieves_set == NULL)
		return (my_puterror("fill achievement: lookup achievements:"),
		WRONG_CONFIG_PATH);
	DR(set_texture_by_setting(rpg->tx_game
			, rpg->achievement->rect, achieves_set));
	fill_it(rpg, achieves_set, name);
	return (SUCCESS);
}
