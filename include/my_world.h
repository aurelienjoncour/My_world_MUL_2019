/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_world
*/

#ifndef MY_WORLD_H_
#define MY_WORLD_H_


#define M_PI    3.1415926535
#define DEG_TO_RAD(x) ((x * M_PI) / 180)

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <math.h>
#include <stdlib.h>
#include "my.h"

sfVector2f project_iso_point(int x, int y, int z, sfVector2f translation);

#endif /* !MY_WORLD_H_ */
