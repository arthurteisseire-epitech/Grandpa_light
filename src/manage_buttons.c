/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** manage button
*/

#include "button.h"
#include "scene.h"
#include "define.h"
#include <SFML/Graphics.h>

int check_over(button_t *button, int x, int y)
{
	sfVector2f pos = sfRectangleShape_getPosition(button->rect);
	sfVector2f rect = sfRectangleShape_getSize(button->rect);

	if (x > pos.x && x < pos.x + rect.x && y > pos.y && y < pos.y + rect.y) {
		sfRectangleShape_setOutlineThickness(button->rect, 2.0);
		return(0);
	}
	sfRectangleShape_setOutlineThickness(button->rect, 0.0);
	return (0);
}

int check_clic(rpg_t *rpg, button_t *button, int x, int y)
{
	sfVector2f pos = sfRectangleShape_getPosition(button->rect);
	sfVector2f rect = sfRectangleShape_getSize(button->rect);

	while (x > pos.x && x < pos.x + rect.x && y > pos.y && y < pos.y + rect.y) {
		sfRectangleShape_setOutlineThickness(button->rect, 4.0);
		button->button_func(rpg);
		return (SUCCESS);
	}
	return (0);
}

int manage_button(rpg_t *rpg, button_t **button, sfEvent *event)
{
	int i = 0;

	while (button != NULL && button[i] != NULL) {
		if (event->type == sfEvtMouseMoved){
			check_over(button[i], event->mouseMove.x, event->mouseMove.y);
		}
		if (event->type == sfEvtMouseButtonPressed){
			check_clic(rpg, button[i], event->mouseButton.x, event->mouseButton.y);
		}
		i++;
	}
	return (0);
}