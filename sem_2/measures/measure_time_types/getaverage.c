#include "getaverage.h"
#include <math.h>

double real_std_err(double avg, const unsigned long long *data, size_t data_size)
{
    double s_sq = 0.0;

    for (size_t i = 0; i < data_size; i++)
        s_sq += (data[i] - avg) * (data[i] - avg);

    s_sq /= (data_size - 1);

    double s = sqrt(s_sq);

    double std_err = s / sqrt(data_size);
    double rse = std_err / avg * 100;

    return rse;
}

double get_average(unsigned long long *data, size_t data_size)
{
    double sum = 0.0;
    for (size_t i = 0; i < data_size; i++)
        sum += (double)data[i];
    double avg = sum / (double)data_size;
    return avg;
}