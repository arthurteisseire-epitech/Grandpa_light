/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <libconfig.h>
#include "rpg.h"
#include "init.h"
#include "states.h"
#include "destroy.h"
#include "define.h"


int main(void)
{
	int status = SUCCESS;
	rpg_t *rpg = malloc(sizeof(rpg_t));

	if (rpg == NULL)
		return (MALLOC_FAILED);
	status = init(rpg);
	if (status != SUCCESS)
		return (status);
	status = game_loop(rpg);
	destroy(rpg);
	return (status);
}

/*
 *int main(void)
 *{
 *        config_t config;
 *        config_setting_t *setting;
 *
 *        config_init(&config);
 *        if (config_read_file(&config, "data/textures.cfg") != CONFIG_TRUE)
 *                return (84);
 *        setting = config_lookup(&config, "textures.texture");
 *        const char *str = config_setting_get_string_elem(setting, 1);
 *        printf("%s\n", str);
 *}
 *
 *int maino()
 *{
 *        config_t config;
 *        const char *str;
 *        int i;
 *
 *        config_init(&config);
 *        if (config_read_file(&config, "./data/test.cfg") != CONFIG_TRUE)
 *                return (84);
 *        if(config_lookup_string(&config, "application.window.title", &str))
 *                printf("Store name: %s\n\n", str);
 *        else
 *                fprintf(stderr, "No 'application.window.title' setting in configuration file.\n");
 *        if (config_lookup_int(&config, "application.window.size.w", &i))
 *                printf("%i\n", i);
 *        else
 *                return (84);
 *        return (0);
 *}
 */
