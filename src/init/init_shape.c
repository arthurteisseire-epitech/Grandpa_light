/*
** EPITECH PROJECT, 2017
** File Name : init_shape.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "libconfig.h"
#include "my.h"
#include "rpg.h"
#include "texture.h"
#include "scene.h"
#include "button.h"
#include "init.h"
#include "define.h"

int init_shape(sfRectangleShape **rect, config_setting_t *parent)
{
	double thick = 0.0;

	*rect = sfRectangleShape_create();
	CM(*rect);
	sfRectangleShape_setPosition(*rect, get_cfg_vec(parent, "pos"));
	sfRectangleShape_setSize(*rect, get_cfg_vec(parent, "size"));
	config_setting_lookup_float(parent, "thick", &thick);
	sfRectangleShape_setOutlineThickness(*rect, thick);
	return (SUCCESS);
}
