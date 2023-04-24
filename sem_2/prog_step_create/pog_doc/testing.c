#include "pop_digit.h"
#include "testing.h"
#include <stdio.h>

void func_test(void)
{
    testing_digit_count();
    testing_get_digits();
    testing_freq_digit();
}

void testing_digit_count(void)
{
    char func_name[] = "void digit_count(int matrix[][M], int n, int m, int dig_arr[])";
    int err_cnt = 0;

    {
        int n = 2;
        int m = 2;
        int dig_arr[10] = {0};
        int matrix[N][M] = {
            {1, 2},
            {1, 2}
        };
        digit_count(matrix, n, m, dig_arr);
        int etalon_arr[DIG_COUNT] = {0, 2, 2, 0, 0, 0, 0, 0, 0, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }

    {
        int n = 1;
        int m = 3;
        int dig_arr[10] = {0};
        int matrix[N][M] = {
            {3, 2, 13}
        };
        digit_count(matrix, n, m, dig_arr);
        int etalon_arr[DIG_COUNT] = {0, 1, 1, 2, 0, 0, 0, 0, 0, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }

    {
        int n = 2;
        int m = 3;
        int dig_arr[10] = {0};
        int matrix[N][M] = {
            {-21, 1, 602},
            {321, 16, 9}
        };
        digit_count(matrix, n, m, dig_arr);
        int etalon_arr[DIG_COUNT] = {1, 4, 3, 1, 0, 0, 2, 0, 0, 1};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }

    printf("%s: %s\n", func_name, err_cnt ? "FAILED" : "OK");
}

void testing_freq_digit(void)
{
    char func_name[] = "int freq_digit(int dig_arr[])";
    int err_cnt = 0;

    {
        int dig_arr[DIG_COUNT] = {0, 2, 2, 0, 0, 0, 0, 0, 0, 0};
        int dig = freq_digit(dig_arr);
        if (dig != 1)
            err_cnt++;
    }

    {
        int dig_arr[DIG_COUNT] = {0, 1, 1, 2, 0, 0, 0, 0, 0, 0};
        int dig = freq_digit(dig_arr);
        if (dig != 3)
            err_cnt++;
    }

    printf("%s: %s\n", func_name, err_cnt ? "FAILED" : "OK");
}

void testing_get_digits(void)
{
    char func_name[] = "void get_digits(int dig_arr[], int num)";
    int err_cnt = 0;

    {
        int n = 0;
        int dig_arr[DIG_COUNT] = {0};
        get_digits(dig_arr, n);
        int etalon_arr[DIG_COUNT] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }
    
    {
        int n = 5;
        int dig_arr[DIG_COUNT] = {1, 4, 0, 0, 0, 0, 0, 0, 4, 0};
        get_digits(dig_arr, n);
        int etalon_arr[DIG_COUNT] = {1, 4, 0, 0, 0, 1, 0, 0, 4, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }
    
    {
        int n = 222;
        int dig_arr[DIG_COUNT] = {1, 2, 0, 0, 0, 0, 0, 0, 4, 0};
        get_digits(dig_arr, n);
        int etalon_arr[DIG_COUNT] = {1, 2, 3, 0, 0, 0, 0, 0, 4, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }

    {
        int n = 342;
        int dig_arr[DIG_COUNT] = {0};
        get_digits(dig_arr, n);
        int etalon_arr[DIG_COUNT] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0};
        if (!diff_arr(dig_arr, etalon_arr))
            err_cnt++;
    }

    printf("%s: %s\n", func_name, err_cnt ? "FAILED" : "OK");
}

bool diff_arr(int arr1[], int arr2[])
{
    for (int i = 0; i < DIG_COUNT; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}