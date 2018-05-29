/*
** EPITECH PROJECT, 2017
** File Name : find_setting_by_name.c
** File description:
** by Arthur Teisseire
*/

#include <libconfig.h>
#include "my.h"

config_setting_t *find_setting_by_name(config_setting_t *array_set
	, const char *name)
{
	config_setting_t *elem;
	char const *str = NULL;
	int i = 0;

	elem = config_setting_get_elem(array_set, i);
	while (elem != NULL) {
		config_setting_lookup_string(elem, "name", &str);
		if (str && my_strcmp(str, name) == 0)
			return (elem);
		i++;
		elem = config_setting_get_elem(array_set, i);
	}
	if (str == NULL)
		return (NULL);
	return (elem);
}

