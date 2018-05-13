/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "button.h"
#include "tool.h"

int update_text(rpg_t *rpg)
{
	const char *actual_str = get_next_dialog(-1);

	if (actual_str == NULL || *actual_str == '\0') {
		rpg->curr_scene = SC_HUB;
		return (1);
	}
	sfText_setString(RPG_SCENE(rpg)->buttons[DIAL_BOX_IDX]->text,
		actual_str);
	return (0);
}