/*
** EPITECH PROJECT, 2017
** File Name : inverse.c
** File description:
** by Arthur Teisseire
*/

void inverse(unsigned int *a, unsigned int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
