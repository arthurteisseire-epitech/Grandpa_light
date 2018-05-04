/*
** EPITECH PROJECT, 2017
** File Name : vec.h
** File description:
** Ozz
*/
#ifndef VEC_H
#define VEC_H

#include <SFML/System/Vector2.h>

sfVector2f coord_mult(sfVector2f v1, sfVector2i v2);
sfVector2f scale_vec(sfVector2f vec1, int factor);
sfVector2f add_vec(sfVector2f vec1, sfVector2f vec2);

#endif
