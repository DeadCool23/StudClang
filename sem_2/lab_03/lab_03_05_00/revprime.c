#include "revprime.h"
#include "errcodes.h"

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void rev_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int add_prime(int matrix[][M], size_t n, size_t m, int array_prime[], size_t *size_arr)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(matrix[i][j]))
            {
                array_prime[*size_arr] = matrix[i][j];
                (*size_arr)++;
            }

    if (*size_arr == 0)
        return ERR_PRIME;
    rev_array(array_prime, *size_arr);
    return OK;
}

void rev_matrix_prime(int matrix[][M], size_t n, size_t m, const int array_prime[])
{
    int index = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = array_prime[index];
                index++;
            }
        }
    }
}