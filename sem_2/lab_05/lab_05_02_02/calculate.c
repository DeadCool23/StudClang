#include "calculate.h"
#include "errs.h"
#include <stddef.h>

int calc_avg(FILE *file, double *avg, size_t *n)
{
    double x_i, sum = 0.0;
    *n = 0;

    while (fscanf(file, "%lf", &x_i) == 1)
    {
        sum += x_i;
        (*n)++;
    }

    if (*n <= 0)
        return ERR_DATA;
    *avg = sum / *n;
    return OK;
}

int calc_disp(FILE *file, double avg, size_t n, double *disp)
{
    double x_i, sq_sum = 0.0;
    size_t n_def = 0;

    while (fscanf(file, "%lf", &x_i) == 1)
    {
        sq_sum += (x_i - avg) * (x_i - avg);
        n_def++;
    }

    if (n_def != n || n_def <= 1)
        return ERR_DATA;
    *disp = sq_sum / n;
    return OK;
}

