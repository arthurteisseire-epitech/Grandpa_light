/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "libconfig.h"

void destroy_config(config_t *config)
{
	config_destroy(config);
}