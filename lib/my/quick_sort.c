/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** quick sort
*/

static void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

void quick_sort(int *array, int idx_begin, int idx_end)
{
    const int pivot = array[idx_begin];
    int cur_left = idx_begin - 1;
    int cur_right = idx_end + 1;

    if (idx_begin - 1 == idx_end)
        return;
    while (1) {
        do {
            cur_left++;
        } while (array[cur_left] < pivot);
        do {
            cur_right--;
        } while (array[cur_right] > pivot);
        if (cur_left >= cur_right)
            break;
        swap(&array[cur_left], &array[cur_right]);
    }
    quick_sort(array, idx_begin, cur_right - 1);
    quick_sort(array, cur_right + 1, idx_end);
}
