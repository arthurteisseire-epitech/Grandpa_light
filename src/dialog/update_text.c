/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "button.h"
#include "tool.h"

int update_text(rpg_t *rpg)
{
	char *actual_str = get_next_dialog(-1);

	if (actual_str == NULL || *actual_str == '\0') {
		free(actual_str);
		rpg->curr_scene = SC_HUB;
		return (1);
	}
	sfText_setColor(RPG_SCENE(rpg)->buttons[DIAL_BOX_IDX]->text, sfBlack);
	sfText_setString(RPG_SCENE(rpg)->buttons[DIAL_BOX_IDX]->text,
		actual_str);
	free(actual_str);
	return (0);
}
