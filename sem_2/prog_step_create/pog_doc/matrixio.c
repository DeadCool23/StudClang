#include "matrixio.h"
#include "errcodes.h"
#include <assert.h>
#include <stdio.h>

int matrix_els(int matrix[][M], int n, int m)
{
    assert ((n > 0 && n <= N) && (m > 0 && m <= M));
    
    printf("Matrix input\n------------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return ERR_IO;
        }
    }
    return OK;
}
