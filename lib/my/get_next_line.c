/*
** EPITECH PROJECT, 2019
** CPE_get_next_line_2019
** File description:
** get next line
*/

#include "get_next_line.h"

static int alloc_buffer(char **buffer, int nb_bloc, int size_buffer)
{
    char *new_buffer = malloc(sizeof(char) * READ_SIZE * nb_bloc);

    if (!new_buffer)
        return MEXIT_ERROR;
    if (*buffer != NULL) {
        for (int i = 0; i < size_buffer; i++)
            new_buffer[i] = (*buffer)[i];
        free(*buffer);
    }
    *buffer = new_buffer;
    return EXIT_SUCCESS;
}

static int get_newline_idx(char *buffer, int size, int ret)
{
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n')
            return i;
    }
    if (ret != READ_SIZE)
        return size;
    return -1;
}

static int read_file(int fd, char **buffer, int *idx, int nb_bloc)
{
    static int ret = READ_SIZE;
    int ret_alloc = 0;
    int new_line_idx = 0;

    while (!(new_line_idx == -1 && ret != READ_SIZE)) {
        if (ret == READ_SIZE && get_newline_idx(*buffer, *idx, ret) == -1) {
            ret = read(fd, ((*buffer) + (*idx)), READ_SIZE);
            (*idx) += ret;
        }
        if (ret == -1 || (ret == 0 && *idx == 0))
            return MEXIT_ERROR;
        new_line_idx = get_newline_idx(*buffer, *idx, ret);
        if (new_line_idx != -1)
            return new_line_idx;
        else if (ret == READ_SIZE)
            ret_alloc = alloc_buffer(buffer, (++nb_bloc), *idx);
        if (ret_alloc == MEXIT_ERROR)
            return MEXIT_ERROR;
    }
    return *idx;
}

static char *get_line_and_clean_buffer(char *buffer, int *size_buffer,
int idx_newline_char)
{
    char *line = malloc(sizeof(char) * idx_newline_char + 1);

    if (!line || !(*size_buffer))
        return NULL;
    for (int i = 0; i < idx_newline_char; i++)
        line[i] = buffer[i];
    line[idx_newline_char] = '\0';
    *size_buffer -= (idx_newline_char + 1);
    for (int i = 0; i < (*size_buffer); i++)
        buffer[i] = buffer[i + idx_newline_char + 1];
    return line;
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    static int size_buffer = 0;
    int nb_bloc;
    int idx_newline_char;

    if (size_buffer == -1)
        return NULL;
    nb_bloc = (size_buffer / READ_SIZE) + 1;
    if ((size_buffer % READ_SIZE) != 0)
        nb_bloc++;
    if (alloc_buffer(&buffer, nb_bloc, size_buffer) == MEXIT_ERROR)
        return NULL;
    idx_newline_char = read_file(fd, &buffer, &size_buffer, nb_bloc);
    if (idx_newline_char == MEXIT_ERROR) {
        free(buffer);
        buffer = NULL;
        return NULL;
    } else if (idx_newline_char == EXIT_END)
        size_buffer = -1;
    return get_line_and_clean_buffer(buffer, &size_buffer, idx_newline_char);
}
