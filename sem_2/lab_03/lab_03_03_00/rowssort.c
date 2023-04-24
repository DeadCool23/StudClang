#include "rowssort.h"
#include <stdbool.h>

int row_sum(const int row[], size_t n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += row[i];
    return sum;
}

void rows_swap(int matrix[][M], size_t index, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        int temp = matrix[index][i];
        matrix[index][i] = matrix[index + 1][i];
        matrix[index + 1][i] = temp;
    }
}

void rows_sort(int matrix[][M], size_t n, size_t m)
{
    bool swapped = true;
    for (size_t i = 0; i < n - 1 && swapped; i++)
    {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (row_sum(matrix[j], m) > row_sum(matrix[j + 1], m))
            {
                rows_swap(matrix, j, m);
                swapped = true;
            }
        }
    }
}
