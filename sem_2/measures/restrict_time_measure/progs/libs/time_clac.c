#include <sys/time.h>
#include "time_clac.h"

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, 0))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}

