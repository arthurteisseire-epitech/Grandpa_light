/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "camera.h"
#include "define.h"
#include "button.h"
#include "character.h"
#include "tile.h"
#include "tool.h"

static void handle_exit(rpg_t *rpg)
{
	if (rpg->event->type == sfEvtClosed)
		sfRenderWindow_close(rpg->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(rpg->window);
}

void player_movement(rpg_t *rpg)
{
	if (rpg->event->key.code == sfKeyZ)
		move_player(rpg, &rpg->character->pos, DIR_UP);
	if (rpg->event->key.code == sfKeyQ)
		move_player(rpg, &rpg->character->pos, DIR_LEFT);
	if (rpg->event->key.code == sfKeyS)
		move_player(rpg, &rpg->character->pos, DIR_DOWN);
	if (rpg->event->key.code == sfKeyD)
		move_player(rpg, &rpg->character->pos, DIR_RIGHT);
}

static void change_scene(rpg_t *rpg)
{
	if (sfKeyboard_isKeyPressed(sfKeyP)) {
		rpg->curr_scene = (rpg->curr_scene + 1) % rpg->nb_scenes;
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			sfRectangleShape_setPosition(rpg->character->rect,
			sfSprite_getPosition(get_map_tile(
			rpg->scenes[rpg->curr_scene]->map, "spawn")->sprite));
	} else if (sfKeyboard_isKeyPressed(sfKeyO)) {
		rpg->curr_scene = (rpg->curr_scene == 0) ?
			rpg->nb_scenes - 1 : rpg->curr_scene - 1;
		if (rpg->scenes[rpg->curr_scene]->map != NULL)
			sfRectangleShape_setPosition(rpg->character->rect,
			sfSprite_getPosition(get_map_tile(
			rpg->scenes[rpg->curr_scene]->map, "spawn")->sprite));
	}
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_exit(rpg);
		if (rpg->scenes[rpg->curr_scene])
			manage_button(rpg, rpg->scenes[rpg->curr_scene]->buttons, rpg->event);
		if (rpg->event->type == sfEvtKeyPressed) {
			player_movement(rpg);
			change_scene(rpg);
		}
	}
	return (SUCCESS);
}
