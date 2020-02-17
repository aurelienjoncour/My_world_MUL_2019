/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task10
*/

static int isal(char c, char type);

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isal(str[i], 'l') && (i == 0 || isal(str[i - 1], 'a') == 0)) {
            str[i] -= 32;
        } else if (i != 0 && isal(str[i], 'u') && isal(str[i - 1], 'a')) {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}
static int isal(char c, char type)
{
    if (type == 'l' && c >= 'a' && c <= 'z')
        return (1);
    if (type == 'u' && c >= 'A' && c <= 'Z')
        return (1);
    if (type == 'a' && ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        return (1);
    if (type == 'a' && c >= '0' && c <= '9')
        return (1);
    return (0);
}
