/*
** EPITECH PROJECT, 2017
** File Name : set_achievement.c
** File description:
** by Arthur Teisseire
*/

#include "libconfig.h"
#include "rpg.h"
#include "vec.h"
#include "achievement.h"
#include "define.h"
#include "font.h"
#include "tool.h"

void set_achievement_color(achievement_t *achievement
, config_setting_t *parent)
{
	int color_nb = 0xff0000;

	config_setting_lookup_int(parent, "xp_color", &color_nb);
	sfText_setColor(achievement->xp_text, HEXA_TO_COLOR(color_nb));
	config_setting_lookup_int(parent, "title_color", &color_nb);
	sfText_setColor(achievement->title, HEXA_TO_COLOR(color_nb));
	config_setting_lookup_int(parent, "desc_color", &color_nb);
	sfText_setColor(achievement->desc, HEXA_TO_COLOR(color_nb));
	config_setting_lookup_int(parent, "head_color", &color_nb);
	sfText_setColor(achievement->head, HEXA_TO_COLOR(color_nb));
}

void set_achievement_pos(achievement_t *achieve
, config_setting_t *parent)
{
	sfVector2f pos = get_cfg_vec(parent, "pos");
	sfVector2f off = get_cfg_vec(parent, "icon_offset");

	sfRectangleShape_setPosition(achieve->rect, pos);
	sfRectangleShape_setPosition(achieve->icon, add_vec(pos, off));
	off = get_cfg_vec(parent, "xp_offset");
	sfText_setPosition(achieve->xp_text, add_vec(pos, off));
	off = get_cfg_vec(parent, "title_offset");
	sfText_setPosition(achieve->title, add_vec(pos, off));
	off = get_cfg_vec(parent, "desc_offset");
	sfText_setPosition(achieve->desc, add_vec(pos, off));
	off = get_cfg_vec(parent, "head_offset");
	sfText_setPosition(achieve->head, add_vec(pos, off));
}

void set_achievement_size(achievement_t *achieve
, config_setting_t *parent)
{
	sfVector2f size = get_cfg_vec(parent, "size");
	int font_size;

	sfRectangleShape_setSize(achieve->rect, size);
	size = get_cfg_vec(parent, "icon_size");
	sfRectangleShape_setSize(achieve->icon, size);
	config_setting_lookup_int(parent, "xp_size", &font_size);
	sfText_setCharacterSize(achieve->xp_text, font_size);
	config_setting_lookup_int(parent, "title_size", &font_size);
	sfText_setCharacterSize(achieve->title, font_size);
	config_setting_lookup_int(parent, "desc_size", &font_size);
	sfText_setCharacterSize(achieve->desc, font_size);
	config_setting_lookup_int(parent, "head_size", &font_size);
	sfText_setCharacterSize(achieve->head, font_size);
}

static int set_font(sfText *text, config_setting_t *parent, char const *name,
font_t **fonts)
{
	font_t *font;
	char const *str = NULL;

	config_setting_lookup_string(parent, name, &str);
	CF(str);
	font = get_font_by_name(fonts, str);
	if (font == NULL) {
		my_puterror("In set_achievement_font : font name not found\n");
		return (WRONG_CONFIG_PATH);
	}
	sfText_setFont(text, font->font);
	return (SUCCESS);
}

int set_achievement_font(achievement_t *achieve
, config_setting_t *parent, font_t **fonts)
{
	DR(set_font(achieve->xp_text, parent, "xp_font", fonts));
	DR(set_font(achieve->title, parent, "title_font", fonts));
	DR(set_font(achieve->desc, parent, "desc_font", fonts));
	DR(set_font(achieve->head, parent, "head_font", fonts));
	return (SUCCESS);
}
