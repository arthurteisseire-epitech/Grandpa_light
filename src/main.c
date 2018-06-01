/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "my.h"
#include "rpg.h"
#include "init.h"
#include "states.h"
#include "destroy.h"
#include "define.h"

int check_env(char **env)
{
	char *str;

	if (env == NULL)
		return (-1);
	str = get_env_value("DISPLAY", env);
	if (str == NULL)
		return (-1);
	free(str);
	return (SUCCESS);
}

int main(int ac, char **av, char **env)
{
	rpg_t *rpg = malloc(sizeof(rpg_t));

	CM(rpg);
	if (ac != 1)
		return (84);
	if (check_env(env) != SUCCESS)
		return (-1);
	(void)av;
	srand((unsigned int)(unsigned long int)rpg);
	DR(init(rpg));
	if (rpg->musics != NULL)
		sfMusic_play(rpg->musics[0]);
	DR(game_loop(rpg));
	destroy(rpg);
	return (SUCCESS);
}
