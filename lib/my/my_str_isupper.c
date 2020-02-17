/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** task15
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 'Z' || str[i] < 'A')
            return (0);
        i++;
    }
    return (1);
}
