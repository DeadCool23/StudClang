#include "delay.h"
#include "clock_gettime_measure.h"
#include <bits/time.h>

unsigned long long calc_work_time(const struct timespec *beg, const struct timespec *end)
{
    return ((unsigned long long) 
            (end->tv_sec - beg->tv_sec) * 1000 * 1000 * 1000 +
            (end->tv_nsec - beg->tv_nsec)) / (1000 * 1000); 
}

unsigned long long measure_by_clock_gettime(int delay_time)
{
    struct timespec time_beg, time_end;
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &time_beg);
    delay(delay_time);
    clock_gettime(CLOCK_MONOTONIC_RAW, &time_end);

    return calc_work_time(&time_beg, &time_end);
}
