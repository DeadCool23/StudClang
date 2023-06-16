#include "calc_measures_res.h"
#include "getaverage.h"
#include "gettimeofday_mesure.h"
#include "clock_gettime_measure.h"
#include "clock_measure.h"
#include "rdtsc_measure.h"
#include <stdio.h>

void gettimeofday_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        for (size_t measure_num = 0; measure_num < N_RES; measure_num++)
            data[measure_num] = measure_by_gettimeofday(meas_delays[delay_num]);
        double avg = get_average(data, N_RES);
        double rse = real_std_err(avg, data, N_RES);
        printf("Average value for testing delay in %d is %.0lf ms (%.2lf%%)\n", meas_delays[delay_num], avg, rse);
    }
}

void clock_gettime_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        for (size_t measure_num = 0; measure_num < N_RES; measure_num++)
            data[measure_num] = measure_by_clock_gettime(meas_delays[delay_num]);
        double avg = get_average(data, N_RES);
        double rse = real_std_err(avg, data, N_RES);
        printf("Average value for testing delay in %d is %.0lf μs (%.2lf%%)\n", meas_delays[delay_num], avg, rse);
    }
}

void clock_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        for (size_t measure_num = 0; measure_num < N_RES; measure_num++)
            data[measure_num] = (unsigned long long)measure_by_clock(meas_delays[delay_num]);
        double avg = get_average(data, N_RES);
        double rse = real_std_err(avg, data, N_RES);
        printf("Average value for testing delay in %d is %.0lf ns (%.2lf%%)\n", meas_delays[delay_num], avg, rse);
    }
}

void rdtsc_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        for (size_t measure_num = 0; measure_num < N_RES; measure_num++)
            data[measure_num] = measure_by_rdtsc(meas_delays[delay_num]);
        double avg = get_average(data, N_RES);
        double rse = real_std_err(avg, data, N_RES);
        printf("Average value for testing delay in %d is %.0lf TSC (%.2lf%%)\n", meas_delays[delay_num], avg, rse);
    }
}