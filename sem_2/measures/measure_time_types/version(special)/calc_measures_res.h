#ifndef MEASURES_RES_H
#define MEASURES_RES_H

#include <stddef.h>

#define N_RES 10

void gettimeofday_measure_res(int *meas_delays, size_t delays_count);

void clock_gettime_measure_res(int *meas_delays, size_t delays_count);

void clock_measure_res(int *meas_delays, size_t delays_count);

void rdtsc_measure_res(int *meas_delays, size_t delays_count);

#endif //MEASURES_RES_H
