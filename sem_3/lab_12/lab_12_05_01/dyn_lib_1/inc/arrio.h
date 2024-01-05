#ifndef __ARRIO_H__
#define __ARRIO_H__

#include <stdbool.h>
#include <stdio.h>

#include "errs.h"

/**
 * @brief Функция счета кол-ва элементов целочисленного массива в файле
 *
 * @param [in, out] file - файл
 * @param [out] n - кол-во элементов
 * @return Код ошибки
 */
err_t fcnt_arr_els(FILE *file, size_t *n);

/**
 * @brief Функция считывания целочисленнго массива из файла
 *
 * @param [in, out] file - файл
 * @param [in, out] arr_beg - начало массива
 * @param [in, out] arr_end - конец массива
 * @return Код ошибки
 */
err_t fread_els_in_arr(FILE *file, int *arr_beg, int *arr_end);

/**
 * @brief Функция записи массива в файл
 * @details Формат: ([0-9]* )*
 *
 * @param [in, out] file - файл
 * @param [in] arr_beg - начало массива
 * @param [in] arr_end - конец массива
 */
void fprint_arr(FILE *file, const int *arr_beg, int *arr_end);

#endif  //__ARRIO_H__
