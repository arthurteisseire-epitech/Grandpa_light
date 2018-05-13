/*
** EPITECH PROJECT, 2017
** File Name : inventory.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include "button.h"
#include "player.h"
#include "define.h"

int set_inventory_text(rpg_t *rpg)
{
	char *nb = my_itoa(rpg->player->stats->nb_orbe);

	CM(nb);
	sfText_setString(rpg->player->items[0]->text, nb);
	free(nb);
	return (SUCCESS);
}
