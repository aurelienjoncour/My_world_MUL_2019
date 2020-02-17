/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task16
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            return (0);
        i++;
    }
    return (1);
}
