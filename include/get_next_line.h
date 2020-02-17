/*
** EPITECH PROJECT, 2019
** CPE_get_next_line_2019
** File description:
** get next line - header
*/

#ifndef H_GET_NEXT_LINE
#define H_GET_NEXT_LINE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE 12
#endif

#define MEXIT_ERROR -1
#define EXIT_END -2

char *get_next_line(int fd);

#endif
