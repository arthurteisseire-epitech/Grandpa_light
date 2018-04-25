/*
** EPITECH PROJECT, 2017
** File Name : free_2d.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

void free_array(void **array)
{
	int i = 0;

	while (array[i] != NULL) {
		free(array[i]);
		i++;
	}
	free(array);
}
