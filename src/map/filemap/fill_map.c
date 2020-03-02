/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** fill_map
*/

#include "my_world.h"

int fill_map(map_t *map_load, char *data)
{
    char **coord_z = my_str_to_word_array(data, " ");
    int foo = 0;

    if (!coord_z)
        return EXIT_FAILURE;
    for (int i = 0; i < map_load->height; i++) {
        for (int j = 0; j < map_load->width; j++) {
            if (coord_z[foo] == NULL)
                return EXIT_FAILURE;
            map_load->map_3d[i][j] = my_getnbr(coord_z[foo]);
            foo++;
        }
    }
    free_2d_array(coord_z);
    return EXIT_SUCCESS;
}

int fill_map_texture(map_t *map_load, char *data)
{
    char **coord_z = my_str_to_word_array(data, " ");
    int foo = 0;

    if (!coord_z)
        return EXIT_FAILURE;
    for (int i = 0; i < map_load->height; i++) {
        for (int j = 0; j < map_load->width; j++) {
            if (coord_z[foo] == NULL)
                return EXIT_FAILURE;
            map_load->texture_const[i][j] = my_getnbr(coord_z[foo]);
            foo++;
        }
    }
    free_2d_array(coord_z);
    return EXIT_SUCCESS;
}