/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task06
*/

void my_swap(int *a, int *b);
static void swap_if_greater(int *array, int i, char *is_sorted);

void my_sort_int_array(int *array, int size)
{
    char is_sorted = 'T';

    do {
        is_sorted = 'T';
        for (int i = 0; i < (size - 1); i++)
            swap_if_greater(array, i, &is_sorted);
    } while (is_sorted == 'F');
}

static void swap_if_greater(int *array, int i, char *sorted)
{
    if (array[i] > array[i + 1]) {
        my_swap(&array[i], &array[i + 1]);
        *sorted = 'F';
    }
}
