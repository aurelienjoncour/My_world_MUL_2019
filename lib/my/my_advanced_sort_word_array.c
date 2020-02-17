/*
** EPITECH PROJECT, 2019
** CPool_Day10_2019
** File description:
** Task04
*/

static void swap_if_true(char **array, int i,
char *sorted, int (*cmp)(char const *, char const *))
{
    char *temp;

    if (cmp(array[i], array[i + 1]) > 0) {
        temp = &array[i][0];
        array[i] = &array[i + 1][0];
        array[i + 1] = temp;
        *sorted = 'F';
    }
}

int my_advanced_sort_word_array(
char **tab, int (*cmp)(char const *, char const *))
{
    int size = 0;
    char is_sorted = 'T';

    while (tab[size] != 0)
        size++;
    do {
        is_sorted = 'T';
        for (int i = 0; i < (size - 1); i++)
            swap_if_true(tab, i, &is_sorted, cmp);
    } while (is_sorted == 'F');
    return (0);
}
