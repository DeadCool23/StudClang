#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "minodd.h"

int main(void)
{
    size_t n, m;
    int matrix[N][M];
    int min_odd;

    int err = square_matrix_input(matrix, &n, &m);
    if (err != OK)
    {
        if (err == ERR_IO)
        {
            printf("IO Error\n");
            return err;
        }
        if (err == ERR_SIZE)
        {
            printf("Size out of range\n");
            return err;
        }
        if (err == ERR_SQUARE)
        {
            printf("Matrix should be square");
            return ERR_SQUARE;
        }
    }

    err = matrix_min_odd(matrix, n, &min_odd);
    if (err != OK)
    {
        if (err == ERR_ODD)
        {
            printf("No odd elements\n");
            return  ERR_ODD;
        }
    }

    printf("Min odd element under main diagonal: %d", min_odd);
    return OK;
}
