/*
** EPITECH PROJECT, 2017
** File Name : save_player_stats.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "rpg.h"
#include "player.h"
#include "define.h"

static int write_player_stat(char *str, int nb, int fd)
{
	char *level = my_itoa(nb);

	CM(level);
	write(fd, str, my_strlen(str));
	write(fd, level, my_strlen(level));
	write(fd, "\n", 1);
	free(level);
	return (SUCCESS);
}

int save_player_stats(player_t *player)
{
	int fd = open("data/player_stats.cfg", O_WRONLY, O_TRUNC);

	if (fd < 0)
		return (WRONG_PATH);
	DR(write_player_stat("level = ", player->stats->level, fd));
	DR(write_player_stat("xp = ", player->stats->xp, fd));
	DR(write_player_stat("xp_to_up = ", player->stats->xp_to_up, fd));
	DR(write_player_stat("light_radius = ", player->stats->light_radius
	, fd));
	DR(write_player_stat("nb_orb = ", player->stats->nb_orbe, fd));
	return (SUCCESS);
}
