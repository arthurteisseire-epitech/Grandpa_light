/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** destroy text
*/

#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>

void destroy_texts(sfText **text)
{
	if (text == NULL)
		return;
	for (unsigned int i = 0; text[i] != NULL; i++)
		sfText_destroy(text[i]);
}
