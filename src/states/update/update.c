/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "button.h"
#include "define.h"
#include "player.h"
#include "tile.h"
#include "particule.h"
#include "cursor.h"

static int mouse_particule(rpg_t *rpg)
{
	sfVector2i rect = sfMouse_getPositionRenderWindow(rpg->window);

	rpg->cursor->particule->rect.left = rect.x;
	rpg->cursor->particule->rect.top = rect.y;
	rpg->cursor->particule->rect.height = 15;
	rpg->cursor->particule->rect.width = 15;
	rpg->cursor->particule->nb_particules = 13;
	gen_particules(rpg->cursor->particule);
	return (0);
}

int update(rpg_t *rpg)
{
	if (CURR_SCENE->map != NULL) {
		set_player_pos(rpg->player);
		player_part(rpg->player);
		update_anim_tiles(rpg, rpg->clock);
		animate_sprite(rpg->player, rpg->clock);
	}
	mouse_particule(rpg);
	return (SUCCESS);
}
