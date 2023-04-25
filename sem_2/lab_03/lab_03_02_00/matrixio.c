#include "matrixio.h"
#include "errcodes.h"
#include <stdio.h>

int matrix_size(size_t *n, size_t *m)
{
    int row, col = 0;
    printf("Input size of matrix: ");
    if (scanf("%d%d", &row, &col) != 2)
        return ERR_IO;
    if ((row <= 0 || row > N) || (col <= 0 || col > M))
        return ERR_SIZE;
    *n = (size_t) row;
    *m = (size_t) col;
    return OK;
}

int matrix_els(int matrix[][M], size_t n, size_t m)
{
    printf("Matrix input\n------------\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return ERR_IO;
        }
    }
    return OK;
}

int matrix_input(int matrix[][M], size_t *n, size_t *m)
{
    int err = matrix_size(n, m);
    if (err != OK)
    {
        return err;
    }
    err = matrix_els(matrix, *n, *m);
    if (err != OK)
    {
        return err;
    }
    return OK;
}

void matrix_output(int matrix[][M], size_t n, size_t m)
{
    printf("Matrix:\n------------\n");
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
