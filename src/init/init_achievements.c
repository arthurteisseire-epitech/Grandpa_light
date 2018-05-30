/*
** EPITECH PROJECT, 2017
** File Name : init_achievements.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "rpg.h"
#include "texture.h"
#include "achievement.h"
#include "define.h"

static int create_sf(rpg_t *rpg)
{
	rpg->achievement->icon = sfRectangleShape_create();
	CM(rpg->achievement->icon);
	rpg->achievement->rect = sfRectangleShape_create();
	CM(rpg->achievement->rect);
	rpg->achievement->title = sfText_create();
	CM(rpg->achievement->title);
	rpg->achievement->desc = sfText_create();
	CM(rpg->achievement->desc);
	rpg->achievement->xp_text = sfText_create();
	CM(rpg->achievement->xp_text);
	rpg->achievement->head = sfText_create();
	CM(rpg->achievement->head);
	return (SUCCESS);
}

int init_achievement(rpg_t *rpg)
{
	config_setting_t *achieves_set;

	achieves_set = config_setting_lookup(rpg->set, "achievements");
	if (achieves_set == NULL) {
		rpg->achievement = NULL;
		return (SUCCESS);
	}
	rpg->achievement = malloc(sizeof(achievement_t));
	CM(rpg->achievement);
	rpg->achievement->nb_achieves = 0;
	rpg->is_achieve = FALSE;
	DR(create_sf(rpg));
	DR(set_texture_by_setting(rpg->tx_game
	, rpg->achievement->rect, achieves_set));
	DR(set_achievement_font(rpg->achievement, achieves_set, rpg->fonts));
	set_achievement_pos(rpg->achievement, achieves_set);
	set_achievement_size(rpg->achievement, achieves_set);
	set_achievement_color(rpg->achievement, achieves_set);
	return (SUCCESS);
}
