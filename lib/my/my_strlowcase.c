/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task09
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] -= ('A' - 'a');
        i++;
    }
    return (str);
}
