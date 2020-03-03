/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** obj
*/

#ifndef OBJ_T_H_
#define OBJ_T_H_

typedef struct object {
    //int matrix_3d[2][2][2];
    sfVector2f matrix_2d[2][2][2];
    sfVertexArray *vrtx_x[2][2];
    sfVertexArray *vrtx_y[2][2];
    sfVertexArray *vrtx_z[2][2];
    //sfVertexArray ***txtr_vrtx_a;
    //sfVertexArray ***txtr_vrtx_b;
    //int **texture_const;
    //sfTexture **textures;
    //sfRenderStates render_state;
    sfVector3f sampling;
    sfVector2f angle;
    sfVector2f origin;
    int height;
    int width;
    sfBool modified;
    sfColor color_line;
} object_t;

sfVector2f obj_project_iso_point(int x, int y, int z, object_t *obj);

#endif
