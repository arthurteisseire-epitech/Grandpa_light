/*
** EPITECH PROJECT, 2017
** File Name : add_arrelem.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

int add_arrelem(void ***array, void *new_item)
{
	int len = my_arrlen(*array);
	void **new_array = malloc(sizeof(void *) * (len + 2));

	if (new_array == NULL)
		return (-1);
	my_arrcpy(new_array, *array);
	new_array[len] = new_item;
	new_array[len + 1] = NULL;
	free(*array);
	*array = new_array;
	return (0);
}
