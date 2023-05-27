#include "delay.h"
#include "rdtsc_measure.h"
#include <x86gprintrin.h>

unsigned long long measure_by_rdtsc(int delay_time)
{
    unsigned long long time_beg, time_end;
    
    time_beg = __rdtsc();
    delay(delay_time);
    time_end = __rdtsc();

    unsigned long long elapsed_time = time_end - time_beg;

    return elapsed_time;
}
