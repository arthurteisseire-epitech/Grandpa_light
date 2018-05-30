/*
** EPITECH PROJECT, 2017
** File Name : destroy_buttons.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "button.h"

static void destroy_button(button_t *button)
{
	sfRectangleShape_destroy(button->rect);
	sfText_destroy(button->text);
	free(button);
}

void destroy_buttons(button_t **buttons)
{
	int i = 0;

	if (buttons == NULL)
		return;
	while (buttons[i] != NULL) {
		destroy_button(buttons[i]);
		i++;
	}
	free(buttons);
}
