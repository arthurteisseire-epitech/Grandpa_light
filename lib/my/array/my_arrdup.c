/*
** EPITECH PROJECT, 2017
** File Name : my_arrdup.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

void **my_arrdup(void **array)
{
	void **res;
	int len;

	len = my_arrlen(array);
	res = malloc(sizeof(void *) * (len + 1));
	my_arrcpy(res, array);
	return (res);
}
