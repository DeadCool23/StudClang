#include <stdio.h>
#include "calc_measures_res.h"

#define DELAYS_COUNT 4
#define MEASURE_METHOD_COUNT 4

#define GETTIMEOFDAY 0
#define CLOCK_GETTIME 1
#define CLOCK 2
#define RDTSC 3

int delays[DELAYS_COUNT] = {
    1000,
    100,
    50,
    10
};

int main()
{
    for (int measure_method = 0; measure_method < MEASURE_METHOD_COUNT; measure_method++)
        switch (measure_method)
        {
        case GETTIMEOFDAY:
            printf("........MEASURE BY GETTIMEOFDAY........\n");
            gettimeofday_measure_res(delays, DELAYS_COUNT);
            printf("\n");
            break;
        case CLOCK_GETTIME:
            printf("........MEASURE BY CLOCK_GETTIME........\n");
            clock_gettime_measure_res(delays, DELAYS_COUNT);
            printf("\n");
            break;
        case CLOCK:
            printf("........MEASURE BY CLOCK........\n");
            clock_measure_res(delays, DELAYS_COUNT);
            printf("\n");
            break;
        case RDTSC:
            printf("........MEASURE BY RDTSC........\n");
            rdtsc_measure_res(delays, DELAYS_COUNT);
            printf("\n");
            break;
        default:
            printf("Udefined method\n");
        }
    return 0;
}
