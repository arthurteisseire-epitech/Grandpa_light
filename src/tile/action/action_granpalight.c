/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include "rpg.h"
#include "button.h"
#include "texture.h"
#include "scene.h"
#include "tile.h"
#include "tool.h"
#include "define.h"

const char dialogs[16][30000] = {
	"Greetings, lost soul. Welcome into my world, you might somewhat lost, "
	"but don't worry, I will guide you. First of all, you shall know why "
	"you are here. This world, as you can see, has slipped down into "
	"darkness. That must be fought. You are the Light which will allow "
	"this place to shine again. You shall bring Enlightenment to this "
	"world. To do so, you must first collect the Orbs of Light, which you "
	"will find in the rooms that you can access from this one. "
	"They will allow you to access deeper, darker, more complex rooms. "
	"And when you find them all, then the Enlightenment shall happen and "
	"the darkness shall scatter. I wish you good luck !",
	"Good job, you are making great progress !",
	"Well, I see that you are advancing in your quest !",
	"Good luck !",
	"You will bring light.",
	"I am looking forward to finally seeing the Enlightenment !",
	"I miss the days this world was shining.",
	"Have you collected enough Orbs to access all the rooms ?",
	"You are worthy of this heavy task.",
	"Soon you will Enlighten this world.",
	"The more you advance, the more you shine. Do you understand ?",
	"Whose world is this in the end ?",
	"Such progression ! You definitely are capable of saving this world.",
	"You are the one improving.",
	"The only thing that matters is the Light.",
	"You have succeeded. You have brought the Enlightenment. But you did "
 	"not bring it to me. All this light is your result. It belongs to you."
  	"You have grown, little light. You are now Enlightening. Leave now "
   	"that you achieved your purpose. And I may now "
 	"rest until another weak light comes to me."};

static int prepare_dialog_scene(rpg_t *rpg, int dialog_nb)
{
	sfText_setString(RPG_SCENE(rpg)->buttons[0]->text, dialogs[dialog_nb]);
	return (0);
}

int action_granpa(rpg_t *rpg, __attribute((unused))tile_t *tile)
{
	int highest_active_chanel = get_highest_active_chanel(RPG_MAP(rpg));
	int dialog;

	rpg->curr_scene = SC_DIALOG;
	rpg->prev_scene = SC_HUB;
	if (highest_active_chanel == 0) {
		open_first_room(rpg);
		dialog = 0;
	} else if (highest_active_chanel < LAST_CHANEL)
		dialog = ((unsigned long int)(&dialog) % 15);
	else
		dialog = LAST_CHANEL;
	DR(prepare_dialog_scene(rpg, dialog));
	return (SUCCESS);
}