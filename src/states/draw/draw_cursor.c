/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** draw cursor
*/

#include "rpg.h"
#include "player.h"
#include "button.h"
#include "states.h"
#include "particule.h"
#include "cursor.h"

void draw_cursor(rpg_t *rpg)
{
	sfRenderWindow_drawVertexArray(rpg->window
	, rpg->cursor->particule->vertex_array, NULL);
}
