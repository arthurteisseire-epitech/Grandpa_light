/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "rpg.h"
#include "scene.h"
#include "tile.h"

tile_t *map_tile(map_t *map, sfVector2f pos)
{
	return (map->tiles[(int)pos.x][(int)pos.y]);
}

tile_t ***rpg_tiles(rpg_t *rpg)
{
	return (rpg->scenes[rpg->curr_scene]->map->tiles);
}

map_t *rpg_map(rpg_t *rpg)
{
	return (rpg->scenes[rpg->curr_scene]->map);
}

scene_t *rpg_scene(rpg_t *rpg)
{
	return (rpg->scenes[rpg->curr_scene]);
}