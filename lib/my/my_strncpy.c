/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int n_greaterthan_src = 0;

    if (n <= 0)
        return (dest);
    while (i < n) {
        if (src[i] == '\0') {
            n_greaterthan_src = 1;
            dest[i] = 0;
        } else if (n_greaterthan_src) {
            dest[i] = 0;
        } else {
            dest[i] = src[i];
        }
        i++;
    }
    return (dest);
}
