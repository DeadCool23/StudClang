#ifndef MEASURES_RES_H
#define MEASURES_RES_H

#include <stddef.h>

/**
 * @def N_RES
 * Максимальное кол-во замеров времени
 */
#define N_RES 1000

/**
 * @def TIME
 * Измерение проводимое в милисекундах
 * @def TSC
 * Измерение проводимое в тиках
 */
#define TIME 0
#define TSC 1

/**
 * @brief Процедура отрисовки головы таблицы
 * @param[in] type - тип измерения
 */
void table_head(int type);

/**
 * @brief Функция построения таблицы замеров с использование gettimeofday
 * 
 * @param[in] meas_delays - массив задержек 
 * @param[in] delays_count - кол-во задержек
 */
void gettimeofday_measure_res(int *meas_delays, size_t delays_count);

/**
 * @brief Функция построения таблицы замеров с использование clock_gettime
 * 
 * @param[in] meas_delays - массив задержек 
 * @param[in] delays_count - кол-во задержек
 */
void clock_gettime_measure_res(int *meas_delays, size_t delays_count);

/**
 * @brief Функция построения таблицы замеров с использование clock
 * 
 * @param[in] meas_delays - массив задержек 
 * @param[in] delays_count - кол-во задержек
 */
void clock_measure_res(int *meas_delays, size_t delays_count);

/**
 * @brief Функция построения таблицы замеров с использование rdtsc
 * 
 * @param[in] meas_delays - массив задержек 
 * @param[in] delays_count - кол-во задержек
 */
void rdtsc_measure_res(int *meas_delays, size_t delays_count);

#endif //MEASURES_RES_H
