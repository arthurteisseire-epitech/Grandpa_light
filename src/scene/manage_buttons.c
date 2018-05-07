/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** manage button
*/

#include <SFML/Graphics.h>
#include "button.h"
#include "scene.h"
#include "define.h"

int check_over(button_t *button, int x, int y)
{
	sfVector2f pos = sfRectangleShape_getPosition(button->rect);
	sfVector2f rect = sfRectangleShape_getSize(button->rect);

	if (x > pos.x && x < pos.x + rect.x && y > pos.y && y < pos.y + rect.y)
		sfRectangleShape_setOutlineThickness(button->rect, 2.0);
	else
		sfRectangleShape_setOutlineThickness(button->rect, 0.0);
	return (SUCCESS);
}

int check_clic(rpg_t *rpg, button_t *button, int x, int y)
{
	sfVector2f pos = sfRectangleShape_getPosition(button->rect);
	sfVector2f rect = sfRectangleShape_getSize(button->rect);

	if (x > pos.x && x < pos.x + rect.x && y > pos.y && y < pos.y + rect.y) {
		sfRectangleShape_setOutlineThickness(button->rect, 4.0);
		if (button->button_func != NULL)
			button->button_func(rpg);
	} else
		sfRectangleShape_setOutlineThickness(button->rect, 0.0);
	return (SUCCESS);
}

int manage_button(rpg_t *rpg, button_t **buttons, sfEvent *event)
{
	int i = 0;

	while (buttons[i] != NULL) {
		if (event->type == sfEvtMouseMoved) {
			check_over(buttons[i], event->mouseMove.x, event->mouseMove.y);
		}
		if (event->type == sfEvtMouseButtonPressed) {
			check_clic(rpg, buttons[i], event->mouseButton.x, event->mouseButton.y);
		}
		i++;
	}
	return (SUCCESS);
}
