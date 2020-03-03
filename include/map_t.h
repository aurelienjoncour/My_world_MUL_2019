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
    sfVertexArray ***vrtx_x;
    sfVertexArray ***vrtx_y;
    sfVertexArray ***txtr_vrtx_a;
    sfVertexArray ***txtr_vrtx_b;
    int **texture_const;
    sfTexture **textures;
    int selected_texture;
    sfRenderStates render_state;
    sfRenderStates rs_black;
    sfVector3f sampling;
    sfVector2f angle;
    sfVector2f origin;
    int height;
    int width;
    sfBool modified;
    sfColor color_line;
} map_t;

enum map_generator_mode {
    DEFAULT,
    SQUARE,
    SQUARE2,
    GEN_LINE
};

#endif /* !MAP_T_H_ */
