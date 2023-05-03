#include "triangle_swap.h"

void rows_els_swap(int back_row[], int forth_row[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        int temp = back_row[i];
        back_row[i] = forth_row[i];
        forth_row[i] = temp;
    }
}

void triangle_up_down(int matrix[][M], size_t n)
{
    for (size_t i = 0; i * i < n; i++)
        rows_els_swap(matrix[i] + i, matrix[n - i - 1] + i, n - 2 * i);
}