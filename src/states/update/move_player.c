/*
** EPITECH PROJECT, 2017
** File Name : move_player.c
** File description:
** Ozz
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include"character.h"
#include"tile.h"
#include"scene.h"
#include"rpg.h"
#include"vec.h"

char is_in_map(map_t *map, sfVector2f pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (0);
	else if (pos.x >= (float)map->size.x || pos.y >= (float)(map->size.y))
		return (0);
	else
		return (1);
}

char collide(map_t *map, sfVector2f pos)
{
	if (is_in_map(map, pos))
		return (map->tiles[(int)pos.x][(int)pos.y]->player_col);
	else
		return (1);
}

void move_player(rpg_t *rpg, sfVector2f *pos, sfVector2f move)
{
	sfVector2f new_pos = add_vec(*pos, move);

	if (!collide(rpg->scenes[rpg->curr_scene]->map, new_pos)) {
		*pos = new_pos;
		update_shader(rpg->scenes[rpg->curr_scene]->map);
	}
}
