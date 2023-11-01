#include "allocate.h"

#include <stdlib.h>

void matrix_free(double **matrix, size_t n)
{
    if (matrix == NULL)
        return;

    double *min_ptr = *matrix;
    for (size_t i = 1; i < n; i++)
        if (min_ptr > matrix[i])
            min_ptr = matrix[i];

    free(min_ptr);
    free(matrix);
}

double **matrix_alloc(size_t n, size_t m)
{
    double **ptrs, *data;
    ptrs = malloc(n * sizeof(*ptrs));
    if (!ptrs)
        return NULL;

    data = malloc(n * m * sizeof(*data));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
        *(ptrs + i) = data + i * m;

    return ptrs;
}

double **matrix_calloc(size_t n, size_t m)
{
    double **ptrs, *data;
    ptrs = malloc(n * sizeof(*ptrs));
    if (!ptrs)
        return NULL;

    data = calloc(n * m, sizeof(*data));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (size_t i = 0; i < n; i++)
        *(ptrs + i) = data + i * m;

    return ptrs;
}

