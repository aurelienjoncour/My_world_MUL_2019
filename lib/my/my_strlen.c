/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (*str != '\0') {
        len++;
        str++;
    }
    return (len);
}
