/*
** EPITECH PROJECT, 2017
** File Name : my_ftoa.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

int get_decimal(float nb, int precision)
{
	if (precision > 5 || precision < 0)
		precision = 6;
	nb -= (int)nb;
	while ((int)nb != nb && precision != 0) {
		nb *= 10;
		precision--;
	}
	return (nb);
}

char *my_ftoa(float nb, int precision)
{
	char *res = NULL;
	char *left;
	char *right;
	int decimal;

	if (nb < 0) {
		res = my_strdup("-");
		nb = -nb;
	}
	decimal = get_decimal(nb, precision);
	left = my_itoa(nb);
	right = my_itoa(decimal);
	res = concat(res, left, my_strlen(left));
	if (precision != 0) {
		res = concat(res, ".", 1);
		res = concat(res, "00000000", precision - nb_len(decimal));
		res = concat(res, right, my_strlen(right));
	}
	free(right);
	return (free(left), res);
}
