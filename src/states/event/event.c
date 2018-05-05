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
	sfVector2f v = rpg->character->pos;
	if (rpg->scenes[rpg->curr_scene]->map)
		if (my_strcmp(rpg->scenes[rpg->curr_scene]->map->tiles[(int)v.x][(int)v.y]->name, "glass") == 0 &&
		rpg->scenes[rpg->curr_scene]->map->tiles[(int)v.x][(int)v.y]->action)
			rpg->scenes[rpg->curr_scene]->map->tiles[(int)v.x][(int)v.y]->action(
			rpg->scenes[rpg->curr_scene]->map,
			rpg->scenes[rpg->curr_scene]->map->tiles[(int)v.x][(int)v.y]);
}

int event(rpg_t *rpg)
{
	while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
		handle_exit(rpg);
		if (rpg->event->type == sfEvtKeyPressed) {
			player_movement(rpg);
			change_scene(rpg);
		}
		if (rpg->scenes[rpg->curr_scene]->buttons != NULL)
			manage_button(rpg, rpg->scenes[rpg->curr_scene]->buttons, rpg->event);
	}
	return (SUCCESS);
}
