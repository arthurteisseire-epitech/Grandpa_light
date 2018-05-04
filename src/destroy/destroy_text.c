/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** destroy text
*/

#include <stddef.h>
#include <SMFL/Graphics.h>

void destroy_text(sfText *text)
{
	sfFont_destroy(sfText_getFont(text));
	sfText_destroy(text);
}

void destroy_texts(sfText **text)
{
	for (unsigned int i = 0; text[i] != NULL; i++)
		destroy_text(text[i]);
}
