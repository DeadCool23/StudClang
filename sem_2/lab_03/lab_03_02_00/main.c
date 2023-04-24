#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "rowsadd.h"

int main(void)
{
    size_t n, m;
    int digit;
    int matrix[2 * N][M];
    int err = matrix_input(matrix, &n, &m);
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
    }
    err = digit_input(&digit);
    if (err != OK)
    {
        if (err == ERR_IO)
        {
            printf("IO Error\n");
            return err;
        }
        if (err == ERR_RANGE)
        {
            printf("Not a digit\n");
            return err;
        }
    }
    rows_add(matrix, &n, m, digit);
    matrix_output(matrix, n, m);
    return OK;
}
