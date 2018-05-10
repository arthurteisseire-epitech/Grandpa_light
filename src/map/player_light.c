/*
** EPITECH PROJECT, 2017
** File Name : player_light.c
** File description:
** Ozz
*/

#include <stdlib.h>
#include <math.h>
#include "tile.h"
#include "scene.h"
#include "vec.h"
#include "tool.h"

sfVector2f get_tile_pos(sfVector2f pos, int angle, int dist)
{
	sfVector2f new_pos;

	new_pos.x = pos.x + dist * cos((float)angle * (PI / 180.0));
	new_pos.y = pos.y + dist * sin((float)angle * (PI / 180.0));
	return (inv_scale_vec(new_pos, SIZE_TILE));
}

float get_dir_scale(sfVector2f dir, int angle)
{
	int dir_angle;

	if (dir.x || dir.y)
		dir_angle = dir.x * 180 + dir.y * 270;
	else
		dir_angle = 0.01 + dir.y * 90;
	return (1 + angle / dir_angle);
}

int ray_collide(map_t *map, sfVector2f pos, int angle, sfVector2f dir)
{
	sfVector2f tile_pos;
	tile_t *tile;
	int i = 0;	
	float light_lv;
	float dir_scale = get_dir_scale(dir, angle);

	while (i < RAYCAST_RADIUS) {
		tile_pos = get_tile_pos(pos, angle, i);
		if (!is_in_map(map, tile_pos)) {
			return (i);
		}
		tile = map->tiles[(int)tile_pos.x][(int)tile_pos.y];
		tile->lighted = 1;
		light_lv = 1 - ((float)i / (float)RAYCAST_RADIUS);
		if (tile->light_level < light_lv)
			tile->light_level = light_lv; 
		if (tile->laser_col) {
			return(i);
		}
		i++;
	}
	return (i);
}

sfColor gen_color(int step)
{
	sfColor color = sfRed;

	color.g = (float)step / (float)RAYCAST_NB * 255.0f;
	color.a = (sfUint8)150;
	return (color);
}

void gen_raycast(map_t *map, sfVector2f pos, sfVector2f dir)
{
	sfRectangleShape **raycast_circle = 
		malloc(sizeof(sfRectangleShape *) * (RAYCAST_NB + 1));
	sfVector2f player_pos = add_vec(scale_vec(pos, SIZE_TILE), VEC_HALF_TILE);
	int angle;
	int tmp_size;

	for (int step = 0; step < RAYCAST_NB; step++) {
		angle = 360 / RAYCAST_NB * (float)step;
		raycast_circle[step] = sfRectangleShape_create();
		sfRectangleShape_setFillColor(raycast_circle[step], gen_color(step));
		sfRectangleShape_setPosition(raycast_circle[step], player_pos);
		sfRectangleShape_setRotation(raycast_circle[step] , angle);
		tmp_size = ray_collide(map, player_pos, angle, dir);
		sfRectangleShape_setSize(raycast_circle[step] , (sfVector2f)
				{tmp_size, 3});
	}
	raycast_circle[RAYCAST_NB] = NULL;	
	map->raycast_circle = raycast_circle;
}
