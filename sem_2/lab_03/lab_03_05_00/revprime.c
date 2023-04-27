#include "revprime.h"
#include "errcodes.h"

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
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

void add_prime(int matrix[][M], size_t n, size_t m, int array_prime[], size_t *size_arr)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(matrix[i][j]))
            {
                array_prime[*size_arr] = matrix[i][j];
                (*size_arr)++;
            }
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
