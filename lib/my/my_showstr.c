/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task20
*/

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base);

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            my_putnbr_base(str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return (0);
}
