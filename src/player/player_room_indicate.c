/*
** EPITECH PROJECT, 2017
** File Name : player_room_indicate.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "player.h"
#include "scene.h"
#include "tile.h"
#include "font.h"
#include "tool.h"
#include "define.h"

static void set_text_help(rpg_t *rpg, player_t *player, sfText *text, char *str)
{
	sfText_setString(text, str);
	sfText_setFont(text, get_font_by_name(rpg->fonts, "default")->font);
	sfText_setPosition(text,
	(sfVector2f){player->pos.x * 64, player->pos.y * 64 - 40});
	sfText_setColor(text, sfWhite);
	sfText_setCharacterSize(text, 20);
}

static sfText *text_help(rpg_t *rpg, player_t *player, tile_t *tile)
{
	int orb_left = tile->chanel - player->stats->nb_orbe;
	char *str;
	sfText *text = sfText_create();

	if (text == NULL)
		return (NULL);
	if (orb_left < 0)
		orb_left = 0;
	str = my_itoa(orb_left);
	if (orb_left == 1)
		str = concat(str, " orb missing to open this door.", 38);
	else
		str = concat(str, " orbs missing to open this door.", 38);
	if (str == NULL)
		return (NULL);
	set_text_help(rpg, player, text, str);
	free(str);
	return (text);
}

int player_room_indicate(rpg_t *rpg, player_t *player)
{
	tile_t *tile = CURR_SCENE->map->tiles[(int)player->pos.x]
	[(int)player->pos.y];
	sfText *text;

	if (tile->func == action_unlocker && !tile->active) {
		text = text_help(rpg, player, tile);
		CM(text);
		sfRenderWindow_drawText(rpg->window, text, NULL);
		sfText_destroy(text);
	}
	return (SUCCESS);
}
