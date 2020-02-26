/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** save_map
*/

#include "my_world.h"

extern const char *MAP_EXTENSION;

static int write_matrix_size(int fd, map_t *map)
{
    char *width = my_putnbr_base_str(map->width, "0123456789");
    char *height = my_putnbr_base_str(map->height, "0123456789");

    if (!width || !height) {
        close(fd);
        return EXIT_ERROR;
    }
    write(fd, width, my_strlen(width));
    write(fd, " ", 1);
    write(fd, height, my_strlen(height));
    write(fd, "\n", 1);
    free(width);
    free(height);
    return EXIT_SUCCESS;
}

int save_map(const char *filename, map_t *map)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    char *str;

    if (fd == -1)
        return EXIT_FAILURE;
    if (write_matrix_size(fd, map))
        return EXIT_ERROR;
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++) {
            str = my_putnbr_base_str(map->map_3d[i][j], "0123456789");
            if (!str)
                return EXIT_FAILURE;
            write(fd, str, my_strlen(str));
            free(str);
            if (i == map->height - 1 && j == map->width - 1);
            else
                write(fd, " ", 1);
        }
    write(fd, "\n", 1);
    close(fd);
    return EXIT_SUCCESS;
}

int auto_save(map_t *map)
{
    char *filename = map->map_name;
    char *map_file = my_str_concat(filename, MAP_EXTENSION);
    int status;

    status = save_map(map_file, map);
    if (status == EXIT_ERROR || status == EXIT_FAILURE)
        my_printf("Failed to save %s !\n", map_file);
    else
        my_printf("Successfuly saved %s !\n", map_file);
    free(map_file);
    return EXIT_SUCCESS;
}