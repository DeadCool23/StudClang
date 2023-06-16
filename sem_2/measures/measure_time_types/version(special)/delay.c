#include "delay.h"
#include <time.h>

void delay(int milliseconds)
{
    struct timespec time_sleep;
    time_sleep.tv_sec = milliseconds / 1000;
    time_sleep.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&time_sleep, NULL);
}