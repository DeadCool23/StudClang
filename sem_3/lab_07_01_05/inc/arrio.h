#ifndef __ARRIO_H__
#define __ARRIO_H__

#include <stdbool.h>
#include <stdio.h>

#include "errs.h"

/**
 * @brief Функция счета кол-ва элементов целочисленного массива в файле
 *
 * @param [in] file - файл
 * @param [out] n - кол-во элементов
 * @return Код ошибки
 */
err_t fcnt_arr_els(FILE *file, size_t *n);

/**
 * @brief Функция считывания целочисленнго массива из файла
 *
 * @param [in] file - файл
 * @param [out] arr - массив
 * @param [in] n - кол-во элементов
 * @return Код ошибки
 */
err_t fread_els_in_arr(FILE *file, int *arr, size_t n);

/**
 * @brief Функция считывания целочисленнго массива из файла
 * @details Память под массив выделяется динамически после подсчета кол-ва элементов в файле
 *
 * @param [in] file - файл
 * @param [out] arr - массив
 * @param [out] n - кол-во элементов
 * @return Код ошибки
 */
err_t fread_arr(FILE *file, int **arr, size_t *n);

/**
 * @brief Функция записи массива в файл
 * @details Формат: ([0-9]* )*
 *
 * @param [out] file - файл
 * @param [in] arr - массив
 * @param [in] n - кол-во элементов массива
 */
void fprint_arr(FILE *file, const int *arr, size_t n);

#endif  //__ARRIO_H__
