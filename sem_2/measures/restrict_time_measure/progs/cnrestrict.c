#include <stddef.h>
#include <stdio.h>
#include "libs/time_clac.h"
#include "libs/errs.h"
#include "libs/matrix_generator.h"

/**
 * @brief Функция подсчета матрицы с = alpha * a + b
 * @details alpha = 10
 * @param[in] a - матрица а
 * @param[in] b - матрица b
 * @param[out] c - матрица c
 * @param[in] n - размерность матриц 
 */
void matrix_sum(const int (*a)[N], const int (*b)[N], int (*c)[N], size_t n);

matrix_t a, b, c;
int main(int argc, char **argv)
{
    if (argc != 2)
        return ERR_ARGS_CNT;
    if (check_arg(argv[1]))
        return ERR_ARG;
    size_t n;
    if (check_arg_range(argv[1], &n))
        return ERR_ARG_RANGE;
    unsigned long long beg, end;
    matrix_generator(a, b, n);
    beg = microseconds_now();
    matrix_sum((const int (*)[N])a, (const int (*)[N])b, (int (*)[N])c, n);
    end = microseconds_now();
    printf("%llu\n", end - beg);
    return OK;
}

void matrix_sum(const int (*a)[N], const int (*b)[N], int (*c)[N], size_t n)
{
    int alpha = 10;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            c[j][i] = alpha * a[j][i] + b[j][i];
}

