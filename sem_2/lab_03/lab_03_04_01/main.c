#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "triangle_swap.h"

int main(void)
{
    size_t n, m;
    int matrix[N][M];

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
        else
        {
            printf("Undefined error\n");
            return err;
        }
    }
    triangle_up_down(matrix, n);
    square_matrix_output(matrix, n);
    return OK;
}
