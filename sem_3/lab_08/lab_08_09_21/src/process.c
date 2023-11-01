#include "process.h"

#include <string.h>

void swap_rows(double **matrix, size_t ind_fst, size_t ind_scd)
{
    double *tmp = matrix[ind_fst];
    matrix[ind_fst] = matrix[ind_scd];
    matrix[ind_scd] = tmp;
}

void matrix_copy(double **dst, const matrix_t *src)
{
    for (size_t i = 0; i < src->rows; i++)
        dst[i] = memcpy(dst[i], src->matrix[i], sizeof(**dst) * src->cols);
}
