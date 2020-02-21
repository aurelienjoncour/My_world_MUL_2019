/*
** EPITECH PROJECT, 2020
** read_entiere_fill
** File description:
** read_entiere_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

static char **read_entiere_file_rec(int fd, int i)
{
    char **file = NULL;
    char *str = NULL;

    str = get_next_line(fd);
    if (str != NULL)
        file = read_entiere_file_rec(fd, i+1);
    if (file == NULL) {
        file = malloc(sizeof(char *) * (i + 2));
        if (file == NULL)
            return NULL;
        file[i+1] = NULL;
    }
    file[i] = str;
    return file;
}

char **read_entiere_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char **file;

    if (fd == -1)
        return NULL;
    file = read_entiere_file_rec(fd, 0);
    close(fd);
    return file;
}
