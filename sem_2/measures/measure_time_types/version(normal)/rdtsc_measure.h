#ifndef RDTSC_MEASURE_H
#define RDTSC_MEASURE_H

/**
 * @brief Функция измерения времени с помощью rdtsc
 * 
 * @param delay_time - время задержки
 * @return Замер времени 
 */
unsigned long long measure_by_rdtsc(int delay_time);

#endif //RDTSC_MEASURE_H