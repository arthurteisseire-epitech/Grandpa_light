/*
** EPITECH PROJECT, 2017
** File Name : destroy_musics.c
** File description:
** by Arthur Teisseire
*/

#include <SFML/Audio.h>
#include <stdlib.h>

void destroy_musics(sfMusic **musics)
{
	int i = 0;

	if (musics == NULL)
		return;
	while (musics[i] != NULL) {
		sfMusic_destroy(musics[i]);
		i++;
	}
	free(musics);
}
