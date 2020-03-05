/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** object
*/

#ifndef OBJ_H_
#define OBJ_H_

typedef struct object {
    int width;
    sfVector2f mtx_2d[2][2][2];
    sfVertexArray *vrtx_x[2][2][2];
    sfVertexArray *vrtx_y[2][2][2];
    sfVertexArray *vrtx_z[2][2][2];
    sfVertexArray *vrtx_txr_a[3];
    sfVertexArray *vrtx_txr_b[3];
    sfTexture *textures[3];
    const char **path_img;
    sfRenderStates render_state;
    sfVector3f size;
    sfVector2f angle;
    sfVector2f origin;
    sfColor line_color;
    sfBool modified;
} object_t;

int object_create(object_t *obj, sfVector2f *position, sfVector3f *sampling,
const char **img_path);

void object_destroy(object_t *obj);

int object_reload(object_t *obj);

int object_display(object_t *obj, sfRenderWindow *win);

int object_rotate(object_t *obj, float anglex, float angley);
int object_translate(object_t *obj, float deltax, float deltay, window_t *w);

void object_2d_matrix_create(object_t *obj);
int object_lines_create(object_t *obj);
int object_texture_create(object_t *obj, const char *img_path[3]);

sfVector2f object_project_iso_point(object_t *obj, int x, int y, int z);



#endif
