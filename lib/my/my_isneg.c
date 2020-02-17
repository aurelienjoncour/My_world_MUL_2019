/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** .
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
