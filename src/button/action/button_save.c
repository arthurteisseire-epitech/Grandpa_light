/*
** EPITECH PROJECT, 2017
** File Name : button_save.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "define.h"

int button_save(rpg_t *rpg)
{
	save_game(rpg);
	return (SUCCESS);
}
