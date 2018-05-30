/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "button.h"
#include "texture.h"
#include "scene.h"
#include "tile.h"
#include "player.h"
#include "tool.h"
#include "define.h"
#include "event.h"
#include "achievement.h"

static int prepare_dialog_scene(rpg_t *rpg, int dialog_nb)
{
	if (RPG_SCENE(rpg)->buttons[DIAL_BOX_IDX]->text != NULL) {
		get_next_dialog(dialog_nb);
		update_text(rpg);
	}
	return (0);
}

int action_granpa(rpg_t *rpg, __attribute((unused))tile_t *tile)
{
	int highest_active_chanel = get_highest_active_chanel(RPG_MAP(rpg));
	int dialog;

	new_achievement(rpg, "granpa_light");
	rpg->curr_scene = SC_DIALOG;
	rpg->prev_scene = SC_HUB;
	if (highest_active_chanel == 0) {
		open_first_room(rpg);
		dialog = 0;
		rpg->player->stats->nb_orbe++;
	} else if (highest_active_chanel < LAST_CHANEL)
		dialog = rand() % 14 + 1;
	else
		dialog = LAST_CHANEL;
	DR(prepare_dialog_scene(rpg, dialog));
	return (SUCCESS);
}
