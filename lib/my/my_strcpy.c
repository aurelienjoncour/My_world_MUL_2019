/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task01
*/

char *my_strncpy(char *dest, char const *src, int n);

char *my_strcpy(char *dest, char const *src)
{
    int size = 0;

    while (src[size] != '\0')
        size++;
    size++;
    return (my_strncpy(dest, src, size));
}
