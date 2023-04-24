#include "pop_digit.h"
#include <assert.h>

void digit_count(int matrix[][M], int n, int m, int dig_arr[])
{
    assert((n > 0 && n <= N) && (m > 0 && m <= M));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            get_digits(dig_arr, matrix[i][j]);
}

void get_digits(int dig_arr[], int num)
{
    num = num < 0 ? -num : num;
    do
    {
        int digit = num % 10;
        dig_arr[digit]++;
        num /=10;
    }
    while (num != 0);
}

int freq_digit(int dig_arr[])
{
    int pop_digit = 0;
    int max_count = dig_arr[0];
    for (int i = 1; i < DIG_COUNT; i++)
    {
        if (dig_arr[i] > max_count)
        {
            pop_digit = i;
            max_count = dig_arr[i];
        }
    }
    return pop_digit;
}
