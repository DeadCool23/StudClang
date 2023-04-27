#include <stdio.h>
#include "errcodes.h"
#include "matrixio.h"
#include "revprime.h"

int main(void)
{
    size_t n, m;
    int matrix[N][M];

    int prime_arr[N * M];
    size_t size_arr = 0;

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
        else
        {
            printf("Undefined error\n");
            return err;
        }
    }

    add_prime(matrix, n, m, prime_arr, &size_arr);
    if (size_arr == 0)
    {
        printf("No prime elements\n");
        return ERR_PRIME;
    }
    rev_array(prime_arr, size_arr);
    rev_matrix_prime(matrix, n, m, prime_arr);
    matrix_output(matrix, n, m);
    return OK;
}
