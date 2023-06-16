#include "calc_measures_res.h"
#include "getaverage.h"
#include "gettimeofday_mesure.h"
#include "clock_gettime_measure.h"
#include "clock_measure.h"
#include "rdtsc_measure.h"
#include <math.h>
#include <stdio.h>

void table_head(int type)
{
    switch (type)
    {
        case TIME:
            printf("| delay time, ms | measure res, ms | runs | rse, %% | abs err, ms | rel err, %% |\n");
            break;
        case TSC:
            printf("| delay time, ms | measure res, TSC | runs | rse, %% |\n");
            break;
    }
}

void gettimeofday_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    table_head(TIME);
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        double avg = 0;
        size_t runs = 0;
        double rse = 100;
        while (rse > MIN_RSE)
        {
            data[runs] = measure_by_gettimeofday(meas_delays[delay_num]);
            runs++;
            if (runs > 2)
            {
                avg = get_average(data, runs);
                rse = real_std_err(avg, data, runs);
            }
        }
        double abs_err = fabs((double)meas_delays[delay_num] - avg);
        double rel_err = (abs_err / (double)meas_delays[delay_num]) * 100.0;
        printf("|%16d|%17.2f|%6zu|%8.2f|%13.2f|%12.2f|\n", meas_delays[delay_num], avg, runs, rse, abs_err, rel_err);
    }
}

void clock_gettime_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    table_head(TIME);
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        double avg = 0;
        size_t runs = 0;
        double rse = 100;
        while (rse > MIN_RSE)
        {
            data[runs] = measure_by_clock_gettime(meas_delays[delay_num]);
            runs++;
            if (runs > 2)
            {
                avg = get_average(data, runs);
                rse = real_std_err(avg, data, runs);
            }
        }
        double abs_err = fabs((double)meas_delays[delay_num] - avg);
        double rel_err = (abs_err / (double)meas_delays[delay_num]) * 100.0;
        printf("|%16d|%17.2f|%6zu|%8.2f|%13.2f|%12.2f|\n", meas_delays[delay_num], avg, runs, rse, abs_err, rel_err);
    }
}

void clock_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    table_head(TIME);
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        double avg = 0;
        size_t runs = 0;
        double rse = 100;
        while (rse > MIN_RSE)
        {
            data[runs] = measure_by_clock(meas_delays[delay_num]);
            runs++;
            if (runs > 2)
            {
                avg = get_average(data, runs);
                rse = real_std_err(avg, data, runs);
            }
        }
        double abs_err = fabs((double)meas_delays[delay_num] - avg);
        double rel_err = (abs_err / (double)meas_delays[delay_num]) * 100.0;
        printf("|%16d|%17.2f|%6zu|%8.2f|%13.2f|%12.2f|\n", meas_delays[delay_num], avg, runs, rse, abs_err, rel_err);
    }
}

void rdtsc_measure_res(int *meas_delays, size_t delays_count)
{
    unsigned long long data[N_RES];
    table_head(TSC);
    for (size_t delay_num = 0; delay_num < delays_count; delay_num++)
    {
        double avg = 0;
        size_t runs = 0;
        double rse = 100;
        while (rse > MIN_RSE)
        {
            data[runs] = measure_by_rdtsc(meas_delays[delay_num]);
            runs++;
            if (runs > 2)
            {
                avg = get_average(data, runs);
                rse = real_std_err(avg, data, runs);
            }
        }
        printf("|%16d|%18.2f|%6zu|%8.2f|\n", meas_delays[delay_num], avg, runs, rse);
    }
}
