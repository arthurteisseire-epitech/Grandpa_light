/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "my.h"
#include "rpg.h"
#include "scene.h"
#include "tile.h"
#include "button.h"
#include "tool.h"

int update_text(button_t *button)
{
	const char *actual_str = get_next_dialog(-1);

	sfText_setString(button->text, actual_str);
	return (actual_str == NULL || *actual_str == '\0');
}