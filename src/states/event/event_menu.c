/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** loop_for_menu
*/

#include <stdio.h>
#include "rpg.h"
#include "define.h"
#include "event.h"

int event_menu(rpg_t *rpg)
{
	handle_exit_key(rpg);
	return (SUCCESS);
}
