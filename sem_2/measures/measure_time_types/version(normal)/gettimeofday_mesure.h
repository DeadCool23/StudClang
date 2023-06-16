#ifndef GETTIME0FDAY_MEASURE_H
#define GETTIME0FDAY_MEASURE_H

/**
 * @brief Процедура получения времени с помощью gettimeofday
 * 
 * @return unsigned long long 
 */
unsigned long long milliseconds_now(void);

/**
 * @brief Функция измерения времени с помощью gettimeofday
 * 
 * @param delay_time - время задержки
 * @return Замер времени 
 */
unsigned long long measure_by_gettimeofday(int delay_time);

#endif //GETTIME0FDAY_MEASURE_H