/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task08
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] += ('A' - 'a');
        i++;
    }
    return (str);
}
