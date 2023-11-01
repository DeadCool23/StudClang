#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <stddef.h>

#include "errs.h"
#include "matrix_struct.h"

/**
 * @brief Фуникция обмена строк матрицы
 *
 * @param [in,out] matrix - матрица
 * @param [in] ind_fst - индекс первой строки
 * @param [in] ind_scd - индекс второй строки
 *
 */
void swap_rows(double **matrix, size_t ind_fst, size_t ind_scd);
/**
 * @brief Функция копирования матрицы
 *
 * @param [out] dst - место вставки
 * @param [in] src - матрица копирования
 * @param [in] n - кол-во строк
 */
void matrix_copy(double **dst, const matrix_t *src);

#endif  //__PROCESS_H__
