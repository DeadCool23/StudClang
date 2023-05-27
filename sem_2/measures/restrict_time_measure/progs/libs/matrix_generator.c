#include "matrix_generator.h"

void matrix_generator(matrix_t fst, matrix_t scd, size_t n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            fst[i][j] = i * n + j + 1;
            scd[i][j] = n * n - (fst[i][j] - 1); 
        }
}
