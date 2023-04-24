#include "condarr.h"
#include <stdio.h>

bool order(int matrix[][M], size_t n, size_t col_num)
{
    if (n == 1)
        return false;
    for (size_t i = 1; i < n; i++)
        if (matrix[i][col_num] >= matrix[i - 1][col_num])
            return false;
    return true;
}

void condarray(int arr[], int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < m; i++)
        arr[i] = order(matrix, n, i) ? 1 : 0;
}

void arr_output(const int arr[], size_t n)
{
    printf("Conditional array: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
