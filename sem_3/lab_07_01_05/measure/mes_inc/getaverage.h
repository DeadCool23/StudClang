#ifndef GETAVERAGE_H
#define GETAVERAGE_H

#include <stddef.h>

/**
 * @def MIN_RSE
 * Минимально допустимая относительная стандартная ошибка среднего
 */
#define MIN_RSE 5.0

/// Максимальное количество замеров
#define N_RES 1000

/**
 * @brief Подсчет относительной стандартной ошибки среднего
 * 
 * @param[in] avg - среднее значение
 * @param[in] data - замеры времени
 * @param[in] data_size - кол-во замеров времени
 * @return относительная стандартная ошибка среднего
 */
double real_std_err(double avg, const unsigned long long *data, size_t data_size);

/**
 * @brief Подсчет среднего значения
 * 
 * @param[in] data - замеры времени
 * @param[in] data_size - кол-во замеров времени
 * @return среднее значение 
 */
double get_average(const unsigned long long *data, size_t data_size);

#endif //GETAVERAGE_H
