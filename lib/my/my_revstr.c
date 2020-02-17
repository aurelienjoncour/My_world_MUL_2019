/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task03
*/

char *my_revstr(char *str)
{
    char temp;
    int len = 0;

    while (str[len] != '\0')
        len++;
    len--;
    for (int i = len; i > (len / 2); i--) {
        temp = str[len - i];
        str[len - i] = str[i];
        str[i] = temp;
    }
    return (str);
}
