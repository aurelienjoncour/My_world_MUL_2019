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
#define SAMPLING 64

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <math.h>
#include <stdlib.h>
#include "my.h"
#include "map_t.h"

sfVector2f project_iso_point(int x, int y, int z, sfVector2f translation);

int **create_3d_map(int height, int width);

void destroy_3d_map(int **map_3d, int height);

sfVector2f **create_2d_map(int **map_3d, int width, int height);

void destroy_2d_map(sfVector2f **map_2d, int height);

#endif /* !MY_WORLD_H_ */
