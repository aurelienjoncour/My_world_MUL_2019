/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_world
*/

#ifndef MY_WORLD_H_
#define MY_WORLD_H_

#define EXIT_ERROR 84

#define M_PI 3.1415926535
#define DEG_TO_RAD(x) ((x * M_PI) / 180)
#define ABS(x) (x < 0) ? (-x) : (x)

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "map_t.h"
#include "event_t.h"
#include "window.h"
#include "event_action.h"
#include "button.h"
#include "text_input.h"
#include "gui.h"
#include "ui_t.h"
#include "image_viewer.h"
#include "state_t.h"

int window_create(window_t *w);
void window_destroy(window_t *w);
int window_run(window_t *w);

int map_create(map_t *map, int height, int width);
int map_display(sfRenderWindow *window, map_t *map);
void map_destroy(map_t *map);
int map_update(map_t *map);

int **create_3d_map(int height, int width);
void destroy_3d_map(int **map_3d, int height);

int create_2d_map(map_t *map);
sfVector2f project_iso_point(int x, int y, int z, map_t *map);
void destroy_2d_map(sfVector2f **map_2d, int height);

int map_vertex_create(map_t *map);
void map_vertex_destroy(map_t *map);

int map_edit_height(map_t *map, float x, float y);

int map_scale(map_t *map, float scale);
int map_translate(map_t *map, float deltax, float deltay);
int map_rotate(map_t *map, float anglex, float angley);
int map_set_angley(map_t *map, float angley);
int map_set_anglex(map_t *map, float anglex);
int map_reset(map_t *map);
int map_resize(map_t *map, sfVector2i resize);

int load_map(const char *filepath, map_t *map);
int save_map(const char *filename, map_t *map);

void soft_state_init(state_t *state);

char *my_str_concat(const char *stra, const char *strb);

#endif /* !MY_WORLD_H_ */
