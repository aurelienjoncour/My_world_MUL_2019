/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** object
*/

#ifndef OBJ_H_
#define OBJ_H_

// MAIN

int object_create(object_t *obj, sfVector2f *position, sfVector3f *sampling,
const char **img_path);

void object_destroy(object_t *obj);

int object_display(object_t *obj, sfRenderWindow *win);

// ON MAP FUNCTIONS

int object_on_map_set_coord(object_t *obj, map_t *map, int x, int y);
int object_on_map_move(object_t *obj, map_t *map, int x, int y);
void object_on_map_refresh(object_t *obj, map_t *map);

// CONFIG

void object_set_size(object_t *obj, int x, int y, int z);

// VIEW EDIT

int object_rotate(object_t *obj, float anglex, float angley);
int object_translate(object_t *obj, float deltax, float deltay, window_t *w);

// SUB FUNCTIONS

int object_reload(object_t *obj);
void object_2d_matrix_create(object_t *obj);
int object_lines_create(object_t *obj);
int object_texture_create(object_t *obj, const char *img_path[3]);
sfVector2f object_project_iso_point(object_t *obj, int x, int y, int z);


#endif
