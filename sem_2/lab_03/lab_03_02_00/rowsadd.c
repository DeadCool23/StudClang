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

void row_assign(int in_row[], const int row_assign[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        in_row[i] = row_assign[i];
}

void row_add(int matrix[][M], int add_row[], size_t index, size_t n, size_t m)
{
    for (size_t i = n + 1; i > index; i--)
        row_assign(matrix[i], matrix[i - 1], m);
    row_assign(matrix[index + 1], add_row, m);
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
    int add_row[M];
    row_form(add_row, m);
    while (i < *n)
    {
        if (row_check(martix[i], m, digit))
        {
            row_add(martix, add_row, i, *n, m);
            i += 2;
            (*n)++;
        }
        else
            i++;
    }
}

void row_form(int row[], size_t m)
{
    for (size_t i = 0; i < m; i++)
        row[i] = ADD_NUM;
}
