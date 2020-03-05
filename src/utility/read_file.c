/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** read file
*/

#include "my_world.h"

static int BUFFER_BLOCK = 42;
static int BUFFER_MAX_LEN = 10000000;

static int realloc_buffer(char **buffer, int *buffer_len, int str_len)
{
    char *new_buffer = malloc(sizeof(char) * (*buffer_len + BUFFER_BLOCK));

    if (!new_buffer)
        return EXIT_FAILURE;
    *buffer_len += BUFFER_BLOCK;
    my_strncpy(new_buffer, *buffer, str_len);
    free(*buffer);
    *buffer = new_buffer;
    return EXIT_SUCCESS;
}

static int read_content(char **content, int *len, int fd)
{
    int buffer_len = BUFFER_BLOCK;
    int ret;

    while (1) {
        ret = read(fd, *content + (*len), BUFFER_BLOCK - 1);
        if (ret == -1)
            return EXIT_FAILURE;
        (*len) += ret;
        if (ret < (BUFFER_BLOCK - 1) || (*len) > BUFFER_MAX_LEN)
            return EXIT_SUCCESS;
        if (realloc_buffer(content, &buffer_len, *len) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
}

char **read_file(const char *filepath)
{
    int fd;
    int len = 0;
    char *content = NULL;
    char **word_array = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr_error("read_file : error fail to open file.\n");
        return NULL;
    }
    if (!(content = malloc(sizeof(char) * BUFFER_BLOCK)))
        return NULL;
    if (read_content(&content, &len, fd) == EXIT_FAILURE) {
        my_putstr_error("read_content : error\n");
        return NULL;
    }
    content[len - 1] = '\0';
    word_array =  my_str_to_word_array(content, "\n");
    free(content);
    return word_array;
}
