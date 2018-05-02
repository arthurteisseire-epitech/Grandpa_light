/*
** EPITECH PROJECT, 2017
** File Name : init_shape.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "my.h"
#include "rpg.h"
#include "texture.h"
#include "scene.h"
#include "button.h"
#include "init.h"
#include "define.h"

int init_shape(rpg_t *rpg, sfRectangleShape **rect, config_setting_t *parent)
{
	int status;
	double thick;

	*rect = sfRectangleShape_create();
	if (*rect == NULL)
		return (MALLOC_FAILED);
	status = set_texture_by_setting(rpg->tx_game, *rect, parent);
	if (status != SUCCESS)
		return (status);
	sfRectangleShape_setPosition(*rect, get_cfg_vec(parent, "pos"));
	sfRectangleShape_setSize(*rect, get_cfg_vec(parent, "size"));
	if (!config_setting_lookup_float(parent, "thick", &thick))
		return (WRONG_CONFIG_PATH);
	sfRectangleShape_setOutlineThickness(*rect, thick);
	return (status);
}
