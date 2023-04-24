#include "rowsadd.h"
#include "errcodes.h"
#include <stdio.h>

int digit_input(int *digit)
{
    int num = 0;
    printf("Input digit: ");
    if (scanf("%d", &num) != 1)
        return ERR_IO;
    if (num < 0 || num >= DIGITS_COUNT)
        return ERR_RANGE;
    *digit = num;
    return OK;
}

void row_add(int matrix[][M], size_t index, size_t n, size_t m)
{
    for (size_t i = n + 1; i > index; i--)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (size_t j = 0; j < m; j++)
        matrix[index + 1][j] = ADD_NUM;
}

void nums_get(int num, int *last, int *first, int digit)
{
    num = num < 0 ? -num : num;
    int last_num = num % 10;
    int first_num;
    do
    {
        first_num = num % 10;
        num /= 10;
    }
    while (num != 0);
    if (first_num == digit)
        (*first)++;
    if (last_num == digit)
        (*last)++;
}

bool row_check(const int row[], size_t m, int digit)
{
    int first_dig = 0;
    int last_dig = 0;
    for (size_t i = 0; i < m; i++)
        nums_get(row[i], &last_dig, &first_dig, digit);
    return (first_dig == last_dig) && (first_dig != 0 || last_dig != 0) ? true : false;
}

void rows_add(int martix[][M], size_t *n, size_t m, int digit)
{
    size_t i = 0;
    while (i < *n)
    {
        if (row_check(martix[i], m, digit))
        {
            row_add(martix, i, *n, m);
            i += 2;
            (*n)++;
        }
        else
            i++;
    }
}
