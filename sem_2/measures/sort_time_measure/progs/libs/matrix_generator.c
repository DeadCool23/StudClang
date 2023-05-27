#include "matrix_generator.h"
#include <stdlib.h>

void random_matrix(size_t n, int *arr)
{
    for (size_t i = 0; i < n; i++)
        arr[i] = rand() % (n + 1);
}

void sorted_matrix(size_t n, int *arr)
{
    for (size_t i = 0; i < n; i++)
        arr[i] = i;
}
