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

char **my_str_to_word_array(char *str, char *delim);

char **read_entiere_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[60000];
    char **file = NULL;
    int size;

    if (fd == -1)
        return NULL;
    size = read(fd, buffer, 60000);
    if (size == -1)
        return NULL;
    buffer[size - 1] = '\0';
    file = my_str_to_word_array(buffer, "\n");
    close(fd);
    return file;
}
