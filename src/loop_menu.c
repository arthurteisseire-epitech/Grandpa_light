/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** loop_for_menu
*/

#include <stdio.h>
#include "rpg.h"
#include "define.h"

int loop_menu(rpg_t __attribute((unused))*rpg)
{
	printf("cette boucle de printf est indépendante des autres scenes, nous somme dans menu\n");
	return (SUCCESS);
}
