/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "rpg.h"
#include "init.h"
#include "states.h"
#include "destroy.h"
#include "parse.h"

int main(void)
{
	int status = 0;
	rpg_t *rpg = malloc(sizeof(rpg_t));

	if (rpg == NULL)
		return (MALLOC_FAILED);
	status = init(rpg);
	if (status != 0)
		return (status);
	status = game_loop(rpg);
	destroy(rpg);
	parse_image(rpg, "assets/images/red_blue_white.png");
	return (status);
}
