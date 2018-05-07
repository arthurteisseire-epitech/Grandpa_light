/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** manage button
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "button.h"
#include "scene.h"
#include "define.h"

int check_over(rpg_t __attribute((unused))*rpg, button_t *button, int x, int y)
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

int manage_buttons(rpg_t *rpg, button_t **buttons, sfEvent *event)
{
	int i = 0;
	int (*mouse_func)(rpg_t *, button_t *, int x, int y) = NULL;
	sfVector2i pos = sfMouse_getPositionRenderWindow(rpg->window);

	if (event->type == sfEvtMouseMoved)
		mouse_func = check_over;
	else if (event->type == sfEvtMouseButtonPressed)
		mouse_func = check_clic;
	if (mouse_func == NULL)
		return (SUCCESS);
	while (buttons[i] != NULL) {
		mouse_func(rpg, buttons[i], pos.x, pos.y);
		i++;
	}
	return (SUCCESS);
}
