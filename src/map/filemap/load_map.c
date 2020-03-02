/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load_map
*/

#include "my_world.h"

bool allow_char(char *script, char *allow_char)
{
    int len_script = my_strlen(script);
    int len_allow = my_strlen(allow_char);
    int cnt = 0;

    for (int i = 0; i  < len_script; i++) {
        cnt = 0;
        for (int j = 0; j < len_allow; j++) {
            if (script[i] == allow_char[j])
                cnt++;
        }
        if (cnt != 1)
            return true;
    }
    return false;
}

static int error_handling(char **file)
{
    if (!file || word_array_len(file) < 1) {
        return EXIT_FAILURE;
    }
    for (int i = 0; file[i] != NULL; i++)
        if (allow_char(file[i], " \t0123456789-"))
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int get_size_map(sfVector2i *size_map, char **file)
{
    char **line = my_str_to_word_array(file[0], " ");

    if (!line)
        return EXIT_FAILURE;
    if (word_array_len(line) != 2) {
        free_2d_array(line);
        return EXIT_FAILURE;
    }
    size_map->x = my_getnbr(line[0]);
    size_map->y = my_getnbr(line[1]);
    free_2d_array(line);
    if (size_map->x < 2 || size_map->y < 2)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int load_map_data(map_t *map_load, char **file)
{
    if (word_array_len(file) > 1)
        fill_map(map_load, file[1]);
    if (word_array_len(file) > 2)
        fill_map_texture(map_load, file[2]);
    return EXIT_SUCCESS;
}

int load_map(const char *filepath, map_t *map)
{
    map_t map_load;
    char **file = read_entiere_file(filepath);
    sfVector2i size_map = {0};

    if (error_handling(file))
        return EXIT_FAILURE;
    if (get_size_map(&size_map, file)) {
        my_putstr_error("load_map : error size map\n");
        return EXIT_FAILURE;
    }
    if (map_create(&map_load, size_map.y, size_map.x))
        return EXIT_FAILURE;
    load_map_data(&map_load, file);
    free_2d_array(file);
    map_destroy(map);
    map_load.modified = true;
    *map = map_load;
    return EXIT_SUCCESS;
}
