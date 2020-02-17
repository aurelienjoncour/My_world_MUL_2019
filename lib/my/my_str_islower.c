/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** task14
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 'z' || str[i] < 'a')
            return (0);
        i++;
    }
    return (1);
}
