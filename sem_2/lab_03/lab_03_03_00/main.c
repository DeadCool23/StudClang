#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "rowssort.h"

int main(void)
{
    size_t n, m;
    int matrix[N][M];
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
    rows_sort(matrix, n, m);
    matrix_output(matrix, n, m);
    return OK;
}
