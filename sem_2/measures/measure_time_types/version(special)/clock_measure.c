#include <time.h>
#include "delay.h"
#include "clock_measure.h"

double measure_by_clock(int delay_time)
{
    clock_t time_beg, time_end;

    time_beg = clock();
    delay(delay_time);
    time_end = clock();

    double elapsed_time_sec = (double) (time_end - time_beg) / CLOCKS_PER_SEC;
    double elapsed_time_mcs = elapsed_time_sec * 1e+9;
    return elapsed_time_mcs;
}
