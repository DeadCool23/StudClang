#ifndef CLOCK_GETTIME_MEASURE_H
#define CLOCK_GETTIME_MEASURE_H

#include <time.h>

/**
 * @brief Функция поиска разности
 * 
 * @param[in] beg - конец замера
 * @param[in] end - начало замера
 * @return Измеренное время 
 */
unsigned long long calc_work_time(const struct timespec *beg, const struct timespec *end);

/**
 * @brief Функция измерения времени с помощью clock_gettime
 * 
 * @param[in] delay_time - время задержки
 * @return Замер времени 
 */
unsigned long long measure_by_clock_gettime(int delay_time);

#endif //CLOCK_GETTIME_MEASURE_H