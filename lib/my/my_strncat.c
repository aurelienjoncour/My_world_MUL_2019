/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** Task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    return (dest);
}
