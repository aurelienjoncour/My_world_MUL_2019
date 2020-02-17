/*
** EPITECH PROJECT, 2019
** CPool_Day10_2019
** File description:
** Task03
*/

static void swap_if_greater(char **array, int i, char *sorted)
{
    char *temp;
    int posX = 0;

    do {
        if (array[i][posX] > array[i + 1][posX]) {
            temp = &array[i][0];
            array[i] = &array[i + 1][0];
            array[i + 1] = temp;
            *sorted = 'F';
        } else if (array[i][posX] == array[i + 1][posX]) {
            posX++;
        }
    } while (array[i][posX] >= array[i + 1][posX]);
}

int my_sort_word_array(char **tab)
{
    int size = 0;
    char is_sorted = 'T';

    while (tab[size] != 0)
        size++;
    do {
        is_sorted = 'T';
        for (int i = 0; i < (size - 1); i++)
            swap_if_greater(tab, i, &is_sorted);
    } while (is_sorted == 'F');
    return (0);
}
