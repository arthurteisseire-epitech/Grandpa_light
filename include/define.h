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
#define CHECK_TEXTURE(tx) if ((tx) == NULL) \
			return (TEXTURE_NOT_FOUND)

#define DR DOMINO_RETURN
#define CM CHECK_MALLOC
#define CF CHECK_FONT
#define CT CHECK_TEXTURE

#define TRUE 1
#define FALSE 0

void my_puterror(char const *str);

#define SUCCESS 0
#define MALLOC_FAILED -2
#define WRONG_PATH -3
#define WRONG_CONFIG_PATH -4
#define TEXTURE_NOT_FOUND -5
#define MUSIC_NOT_FOUND -6
#define SOUND_NOT_FOUND -7
#define FONT_NOT_FOUND -8

#define LAS_STR "laser_beam"
#define CAP_STR "ls_receptor"
#define ROOM_STR "room"
#define DOOR_STR "door"
#define LEV_STR "on_off"
#define ORB_STR "orb"
#define WALL_STR "wall"
#define GROUND_STR "ground"
#define GLASS_STR "glass"
#define SPAWN_STR "spawn"
#define TORCH_STR "torch"
#define UNLOCKER_STR "unlocker"

#endif
