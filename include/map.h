/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

// MAIN FUNCTIONS
int map_create(map_t *map, int height, int width);
int map_display(window_t *w, map_t *map);
void display_texture_water(window_t *w, map_t *map, sfVector2i p);

void map_destroy(map_t *map);
int map_update(map_t *map);
int map_update_all(window_t *w, map_t *map);

int **create_3d_map(int height, int width);
void destroy_3d_map(int **map_3d, int height);

int create_2d_map(map_t *map);
sfVector2f project_iso_point(int x, int y, int z, map_t *map);
void destroy_2d_map(sfVector2f **map_2d, int height);

int map_vertex_create(map_t *map);
void map_vertex_destroy(map_t *map);

// TEXTURE
int map_vertex_texture_create(map_t *map);
void map_vertex_texture_destroy(map_t *map);
void map_texture_destroy(map_t *map);
int map_texture_create(map_t *map);
int map_texture_set_height(map_t *map);

// VIEW TOOLS
int map_scale_all(window_t *w, float scale);
int map_scale(map_t *map, float scale);
int map_translate(map_t *map, float deltax, float deltay, window_t *w);
int map_rotate(map_t *map, float anglex, float angley);
int map_set_angley(map_t *map, float angley);
int map_set_anglex(map_t *map, float anglex);
int map_reset(map_t *map);
int map_resize(map_t *map, sfVector2i resize);
int map_resize_all(window_t *w, sfVector2i resize);

// FILE MAP
int load_map(const char *filepath, map_t *map);
int load_from_argv(char *filename, window_t *w);
int save_map(const char *filename, map_t *map);
int auto_save(map_t *map);
int fill_map(map_t *map_load, char *data);
int fill_map_texture(map_t *map_load, char *data);

// RANDOM MAP
void map_generator(map_t *map);
void map_generator_default(map_t *map);
void map_generator_square(map_t *map);
void map_generator_square_two(map_t *map);
void map_generator_line(map_t *map);
double perlin(double x, double y, int res, unsigned int *perm);
void mix_permutation_table(unsigned int *permutation_table);

// MAP TOOLS FUNCTION
int map_edit_height(window_t *w, float x, float y);
int area_mode(map_t *map, sfVector2f *mouse, int coefficient);
int tiles_mode(map_t *map, sfVector2f *mouse, int coefficient);
int corner_mode(map_t *map, sfVector2f *mouse, int coefficient);
int get_dynamical_coefficient(int point_height);

int texture_area_mode(map_t *map, sfVector2f *mouse, slider_t *slider);
int texture_corner_mode(map_t *map, sfVector2f *mouse);
int texture_tiles_mode(map_t *map, sfVector2f *mouse);
int map_edit_texture(window_t *w, float x, float y);

#endif
