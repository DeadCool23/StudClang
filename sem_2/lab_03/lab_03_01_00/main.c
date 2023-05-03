#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "condarr.h"

int main(void)
{
    size_t n, m;
    int matrix[N][M];
    int cols[M];
    int err = matrix_input(matrix, &n, &m);
    if (err != OK)
    {
        err_output(err);
        return err;
    }
    condarray(cols, matrix, n, m);
    arr_output(cols, m);
    return OK;
}
