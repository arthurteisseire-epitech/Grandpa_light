/*
** EPITECH PROJECT, 2017
** File Name : button_credit.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "scene.h"
#include "define.h"

int button_exit(rpg_t *rpg)
{
	sfRenderWindow_close(rpg->window);
	save_scenes(rpg);
	return (SUCCESS);
}
