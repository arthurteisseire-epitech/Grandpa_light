/*
** EPITECH PROJECT, 2017
** File Name : my_pow.c
** File description:
** by Arthur Teisseire
*/

int my_pow(int nb, int pow)
{
	int res = 1;
	int i = 0;

	while (i < nb) {
		res *= pow;
		i++;
	}
	return (res);
}
