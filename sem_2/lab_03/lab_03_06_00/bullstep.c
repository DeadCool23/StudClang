#include "bullstep.h"

void bull_step(int matrix[][M], size_t n, size_t m)
{
    int count = 0;
    for (size_t j = 0; j < m; j++)
    {
        if (j % 2 == 0)
            for (int i = 0; i < (int) n; i++)
                matrix[i][j] = ++count;
        else
            for (int i = (int) (n - 1); i >= 0; i--)
                matrix[i][j] = ++count;
    }
}
