/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <SFML/System/Types.h>
#include "define.h"
#include "rpg.h"

int init_clock(sfClock **clock)
{
	*clock = sfClock_create();

	CM(*clock);
	return (SUCCESS);
}
