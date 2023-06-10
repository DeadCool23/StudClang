#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>

/**
 * @brief Функция поиска среднего значения
 * @param[in] file - файловая переменная
 * @param[out] avg - среднее значение
 * @param[in,out] n - кол-во считаемых элементов
 * @return Код ошибки
 */
int calc_avg(FILE *file, double *avg, size_t *n);

/**
 * @brief Функция поиска дисперсии
 * @param[in] file - файловая переменная
 * @param[in] avg - среднее значение
 * @param[in] n - кол-во считаемых элементов
 * @param[out] disp - дисперсия
 * @return Код ошибки
 */
int calc_disp(FILE *file, double avg, size_t n, double *disp);

#endif //CALCULATE_H
