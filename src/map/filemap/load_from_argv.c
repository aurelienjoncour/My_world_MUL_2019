/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load_from_argv
*/

#include "my_world.h"

extern const char *MAP_EXTENSION;

int load_from_argv(char *filename, window_t *w)
{
    int i = my_strlen(filename) - my_strlen(MAP_EXTENSION);
    char *map_file = NULL;

    if (load_map(filename, &w->map) == EXIT_FAILURE) {
        my_printf("Error : fail to load map file :: (%s)\n", filename);
        return EXIT_ERROR;
    }
    map_file = my_strdup(filename);
    if (!map_file) {
        my_printf("Error : fail to load map file :: (%s)\n", filename);
        return EXIT_ERROR;
    }
    map_file[i] = '\0';
    free(w->map.map_name);
    w->map.map_name = map_file;
    sfText_setString(w->ui.txt_map_name, w->map.map_name);
    text_input_set_content(&w->ui.edit_map_name, w->map.map_name);
    text_input_set_content(&w->ui.load_map_file, w->map.map_name);
    return EXIT_SUCCESS;
}
