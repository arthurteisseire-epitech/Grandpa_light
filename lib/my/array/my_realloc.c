/*
** EPITECH PROJECT, 2017
** File Name : my_realloc.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

void *my_realloc(void **array, void *data)
{
	int i = 0;
	void **ptr1 = array;
	void **new = malloc(sizeof(void *) * (my_arrlen(array) + 2));

	while (ptr1[i] != NULL) {
		new[i] = ptr1[i];
		i++;
	}
	new[i] = data;
	new[i + 1] = NULL;
	return (new);
}
