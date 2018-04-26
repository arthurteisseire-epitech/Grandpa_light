/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "rpg.h"
#include "init.h"
#include "states.h"
#include "destroy.h"

/*int main(void)
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
	return (status);
}*/

#include <stdio.h>

int main(void)
{
	config_t *config = NULL;
	config_init(config);
	FILE *file = fopen("test.cfg", "r");

	int ret = config_read(config, file);
	printf("ret = %d\n", ret);
}
