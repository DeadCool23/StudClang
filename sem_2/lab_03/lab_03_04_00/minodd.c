#include "minodd.h"
#include "errcodes.h"
#include <stdbool.h>

int matrix_min_odd(int matrix[][M], size_t n, int *min)
{
    bool odd = false;

    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            int el = matrix[i][j];
            if (((el & EVEN_BIT) == 1) && (!odd || *min > el))
            {
                odd = true;
                *min = el;
            }
        }
    }

    if (!odd)
        return ERR_ODD;

    return OK;
}
