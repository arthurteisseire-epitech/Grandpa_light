/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by Adrien FABRE,
*/

#include <stddef.h>
#include "my.h"

const char dialogs[12][30000] = {
	"Greetings, lost light.;Welcome into this world,\n"
	"you might be somewhat lost,\n"
	"but don't worry, I will guide you.;First of all, you shall know why "
	"you are here.;This world, as you can see,\nhas slipped down into "
	"darkness.;That must be fought.;You are the Light which will allow "
	"this place\nto shine again.;You shall bring Enlightenment to this "
	"world.;To do so, you must first collect the Orbs of Light,\n which you"
	" will find in the surrounding rooms;"
	"They will allow you to access deeper, \ndarker, more complex rooms.;"
	"And when you find them all, then the Enlightenment\nshall happen and "
	"the darkness shall scatter.;I wish you good luck !;",
	"Good job, you are making great progress !;",
	"Well, I see that you are advancing in your quest !;", "Good luck !;",
	"I am looking forward to finally seeing the Enlightenment !;",
	"I miss the days this world was shining.;",
	"Have you collected enough Orbs to access all the rooms ?;",
	"You are worthy of this heavy task.;",
	"Soon you will Enlighten this world.;",
	"The more you advance, the more you shine.;Do you understand ?;",
	"Whose world is this in the end ?;",
	"You have succeeded.;You have brought the Enlightenment.;But you did "
	"not bring it to me.;All this light is your result.;It belongs to you."
	"You have grown, little light.;You are now Enlightening.;Leave now "
	"that you achieved your purpose.;And I may now "
	"rest until another weak light comes to me.;"
};

char *get_next_dialog(int idx)
{
	static int act_idx = 0;
	static char *next_ptr;
	char *str = NULL;

	if (idx >= 0) {
		act_idx = idx;
		next_ptr = (char *)dialogs[act_idx];
	} else {
		str = get_before_to(next_ptr, ";");
		next_ptr = my_strstr(next_ptr, ";") + 1;
	}
	return (str);
}
