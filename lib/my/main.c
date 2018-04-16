/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int main(void)
{
	char *str;

	while ((str = get_next_line(0)))
		printf("%s\n", str);
	return (0);
}
