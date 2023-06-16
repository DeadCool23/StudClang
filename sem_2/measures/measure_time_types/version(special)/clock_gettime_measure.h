#ifndef CLOCK_GETTIME_MEASURE_H
#define CLOCK_GETTIME_MEASURE_H

#include <time.h>

unsigned long long calc_work_time(const struct timespec *beg, const struct timespec *end);

unsigned long long measure_by_clock_gettime(int delay_time);

#endif //CLOCK_GETTIME_MEASURE_H