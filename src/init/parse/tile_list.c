/*
** EPITECH PROJECT, 2017
** File Name : obj_list.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "rpg.h"
#include "tile.h"
#include "define.h"
#include "texture.h"

const tile_list_t tile_list[NB_TILE] = {
	{{0x00, 0x00, 0x01, 0x00},
		"wall", TRUE, TRUE, NULL, TX_TILE_WALL},
	{{0x00, 0x00, 0x02, 0x00},
		"ground", FALSE, FALSE, NULL, TX_TILE_GROUND},
	{{0x00, 0x00, 0x03, 0x00},
		"glass", TRUE, FALSE, NULL, TX_TILE_GLASS},
	{{0x00, 0x00, 0x04, 0x00},
		"spawn", FALSE, FALSE, NULL, TX_TILE_SPAWN},
	{{0x00, 0x00, 0x05, 0x00},
		"end", FALSE, FALSE, NULL, TX_TILE_END},
	{{0x00, 0x00, 0x06, 0x00}, "laser", 
	/*
	 *{{0x00, 0x00, 0x06, 0x00},
	 *        "door", TRUE, TRUE, NULL, TX_TILE_DOOR},
	 *{{0x00, 0x00, 0x07, 0x00},
	 *        "switch", FALSE, TRUE, NULL, TX_TILE_SWITCH},
	 *{{0x00, 0x00, 0x08, 0x00},
	 *        "ls_beam", TRUE, TRUE, NULL, TX_TILE_LS_BEAM},
	 *{{0x00, 0x00, 0x0a, 0x00},
	 *        "ls_receptor", TRUE, TRUE, NULL, TX_TILE_LS_RECEPTOR}
	 */
};

int index_tile_by_color(sfColor color)
{
	for (int i = 0; i < NB_TILE; i++)
		if ((MASK_NAME(tile_list[i].color) == (MASK_NAME(color))))
			return (i);
	return (0);
}
