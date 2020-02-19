/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_t
*/

#ifndef MAP_T_H_
#define MAP_T_H_

#include "my_world.h"

typedef struct world_map {
    char *map_name;
    int **map_3d;
    sfVector2f **map_2d;
    sfVertexArray **vrtx_x;
    sfVertexArray **vrtx_y;
    sfVector3f sampling;
    sfVector2f angle;
    sfVector2f origin;
    int height;
    int width;
    sfBool modified;
} map_t;

#endif /* !MAP_T_H_ */
