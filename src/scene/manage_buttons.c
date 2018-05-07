/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** manage button
*/

#include "rpg.h"
#include "button.h"
#include "scene.h"
#include "define.h"
#include "tool.h"

int check_over(rpg_t *rpg, button_t *button, sfVector2i pos)
{
	sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

	(void)rpg;
	if (is_pos_in_rect(pos, rect))
		sfRectangleShape_setOutlineThickness(button->rect, 2.0);
	else
		sfRectangleShape_setOutlineThickness(button->rect, 0.0);
	return (SUCCESS);
}

int check_clic(rpg_t *rpg, button_t *button, sfVector2i pos)
{
	sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

	if (is_pos_in_rect(pos, rect)) {
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
	int (*mouse_func)(rpg_t *, button_t *, sfVector2i) = NULL;
	sfVector2i pos = sfMouse_getPositionRenderWindow(rpg->window);

	if (event->type == sfEvtMouseMoved)
		mouse_func = check_over;
	else if (event->type == sfEvtMouseButtonPressed)
		mouse_func = check_clic;
	if (mouse_func == NULL)
		return (SUCCESS);
	while (buttons[i] != NULL) {
		mouse_func(rpg, buttons[i], pos);
		i++;
	}
	return (SUCCESS);
}
