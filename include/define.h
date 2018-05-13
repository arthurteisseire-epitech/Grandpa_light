/*
** EPITECH PROJECT, 2017
** File Name : define.h
** File description:
** by Arthur Teisseire
*/

#ifndef DEFINE_H
#define DEFINE_H

#define DOMINO_RETURN(status) if ((status) != SUCCESS) \
			return (status)
#define CHECK_MALLOC(ptr) if ((ptr) == NULL) \
			return (MALLOC_FAILED)
#define CHECK_FONT(ptr) if ((ptr) == NULL) \
			return (FONT_NOT_FOUND)

#define DR DOMINO_RETURN
#define CM CHECK_MALLOC
#define CF CHECK_FONT

#define TRUE 1
#define FALSE 0

void my_puterror(char const *str);

#define SUCCESS 0
#define MALLOC_FAILED my_puterror("Malloc failed\n"), -2
#define WRONG_PATH my_puterror("Wrong file path\n"), -3
#define WRONG_CONFIG_PATH my_puterror("In .cfg: Wrong config path\n"), -4
#define TEXTURE_NOT_FOUND my_puterror("In .cfg: Texture not found\n"), -5
#define MUSIC_NOT_FOUND my_puterror("In .cfg: Music not found\n"), -5
#define SOUND_NOT_FOUND my_puterror("In .cfg: Sound not found\n"), -5
#define FONT_NOT_FOUND my_puterror("In .cfg: Font not found\n"), -5

#define LAS_STR "laser_beam"
#define CAP_STR "ls_receptor"
#define ROOM_STR "room"
#define DOOR_STR "door"
#define LEV_STR "on_off"
#define END_STR "end"
#define WALL_STR "wall"
#define GROUND_STR "ground"
#define GLASS_STR "glass"
#define SPAWN_STR "spawn"
#define UNLOCKER_STR "unlocker"

#endif
