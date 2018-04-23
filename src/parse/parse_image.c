/*
** EPITECH PROJECT, 2017
** File Name : parse_image.c
** File description:
** by Arthur Teisseire
*/

#include "rpg.h"
#include "parse.h"
#include "object.h"

int parse_image(rpg_t *rpg, char *path)
{
	int status = 0;
	sfImage *image = sfImage_createFromFile(path);
	sfColor color = sfImage_getPixel(image, 0, 0);

	for (int i = 0; i < NB_OBJ; i++) {
		printf("color: r%d, g%d, b%d\n", color.r, color.g, color.a);
	}
	return (status);
}
