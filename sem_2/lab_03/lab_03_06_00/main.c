#include "errcodes.h"
#include "matrixio.h"
#include "bullstep.h"
#include <stdio.h>

int main(void)
{
    size_t n, m;
    int matrix[N][M];
    int err = matrix_size(&n, &m);
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
        else
        {
            printf("Undefined error\n");
            return err;
        }
    }
    bull_step(matrix, n, m);
    matrix_output(matrix, n, m);
    return OK;
}
