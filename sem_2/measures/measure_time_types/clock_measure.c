#include <time.h>
#include "delay.h"
#include "clock_measure.h"

unsigned long long measure_by_clock(int delay_time)
{
    clock_t time_beg, time_end;

    time_beg = clock();
    delay(delay_time);
    time_end = clock();

    double elapsed_time_sec = (double)(time_end - time_beg) / CLOCKS_PER_SEC;
    unsigned long long elapsed_time_ms = (unsigned long long)(elapsed_time_sec * 1000);
    return elapsed_time_ms;
}
