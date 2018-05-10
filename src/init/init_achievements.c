/*
** EPITECH PROJECT, 2017
** File Name : init_achievements.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include <stdlib.h>
#include "rpg.h"
#include "texture.h"
#include "achievement.h"
#include "init.h"
#include "define.h"

static void set_achievement_pos(achievement_t *achieve
, config_setting_t *parent)
{
	sfVector2f pos = get_cfg_vec(parent, "pos");
	sfVector2f off = get_cfg_vec(parent, "icon_offset");

	sfRectangleShape_setPosition(achieve->rect, pos);
	sfRectangleShape_setPosition(achieve->icon, (sfVector2f){pos.x + off.x, pos.y + off.y});
	off = get_cfg_vec(parent, "xp_offset");
	sfText_setPosition(achieve->xp, (sfVector2f){pos.x + off.x, pos.y + off.y});
	off = get_cfg_vec(parent, "title_offset");
	sfText_setPosition(achieve->title, (sfVector2f){pos.x + off.x, pos.y + off.y});
	off = get_cfg_vec(parent, "desc_offset");
	sfText_setPosition(achieve->desc, (sfVector2f){pos.x + off.x, pos.y + off.y});
}

static void set_achievement_size(achievement_t *achieve
, config_setting_t *parent)
{
	sfVector2f size = get_cfg_vec(parent, "size");
	int font_size;
	
	sfRectangleShape_setSize(achieve->rect, size);
	size = get_cfg_vec(parent, "icon_size");
	sfRectangleShape_setSize(achieve->icon, size);
	config_setting_lookup_int(parent, "xp_size", &font_size);
	sfText_setCharacterSize(achieve->xp, font_size);
	config_setting_lookup_int(parent, "title_size", &font_size);
	sfText_setCharacterSize(achieve->title, font_size);
	config_setting_lookup_int(parent, "desc_size", &font_size);
	sfText_setCharacterSize(achieve->desc, font_size);
}

static int set_achievement_font(achievement_t *achieve
, config_setting_t *parent)
{
	sfFont *font;
	char const *str = NULL;

	config_setting_lookup_string(parent, "xp_font", &str);
	if (str == NULL)
		return (FONT_NOT_FOUND);
	font = sfFont_createFromFile(str);
	CM(font);
	sfText_setFont(achieve->xp, font);
	config_setting_lookup_string(parent, "title_font", &str);
	if (str == NULL)
		return (FONT_NOT_FOUND);
	font = sfFont_createFromFile(str);
	CM(font);
	sfText_setFont(achieve->title, font);
	config_setting_lookup_string(parent, "desc_font", &str);
	if (str == NULL)
		return (FONT_NOT_FOUND);
	font = sfFont_createFromFile(str);
	CM(font);
	sfText_setFont(achieve->desc, font);
	return (SUCCESS);
}

int init_achievement(rpg_t *rpg)
{
	config_setting_t *achieves_set;

	achieves_set = config_setting_lookup(rpg->set, "achievements");
	if (achieves_set == NULL)
		return (WRONG_CONFIG_PATH);
	rpg->achievement = malloc(sizeof(achievement_t));
	CM(rpg->achievement);
	rpg->achievement->icon = sfRectangleShape_create();
	CM(rpg->achievement->icon);
	rpg->achievement->rect = sfRectangleShape_create();
	CM(rpg->achievement->rect);
	rpg->achievement->title = sfText_create();
	CM(rpg->achievement->title);
	rpg->achievement->desc = sfText_create();
	CM(rpg->achievement->desc);
	rpg->achievement->xp = sfText_create();
	CM(rpg->achievement->xp);
	DR(set_texture_by_setting(rpg->tx_game, rpg->achievement->rect, achieves_set));
	DR(set_achievement_font(rpg->achievement, achieves_set));
	set_achievement_pos(rpg->achievement, achieves_set);
	set_achievement_size(rpg->achievement, achieves_set);
	return (SUCCESS);
}
