#include "delay.h"
#include "gettimeofday_mesure.h"
#include <sys/time.h>
#include <stddef.h>

unsigned long long milliseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL + val.tv_usec / 1000ULL;
}

unsigned long long measure_by_gettimeofday(int delay_time)
{
    long long unsigned beg, end;

    beg = milliseconds_now();
    delay(delay_time);
    end = milliseconds_now();

    return end - beg;
}
