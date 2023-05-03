#include "rowssort.h"
#include <stdbool.h>

int row_sum(const int row[], size_t n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += row[i];
    return sum;
}

void rows_swap(int back_row[], int forth_row[], size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        int temp = back_row[i];
        back_row[i] = forth_row[i];
        forth_row[i] = temp;
    }
}

//void rows_bubble_sort(int matrix[][M], size_t n, size_t m)
//{
//    bool swapped = true;
//    for (size_t i = 0; i < n - 1 && swapped; i++)
//    {
//        swapped = false;
//        for (size_t j = 0; j < n - i - 1; j++)
//        {
//            if (row_sum(matrix[j], m) > row_sum(matrix[j + 1], m))
//            {
//                rows_swap(matrix[j], matrix[j + 1], m);
//                swapped = true;
//            }
//        }
//    }
//}

void rows_selection_sort(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        int min_ind = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (row_sum(matrix[j], m) <= row_sum(matrix[min_ind], m))
                min_ind = j;
        }
        rows_swap(matrix[i], matrix[min_ind], m);
    }
}