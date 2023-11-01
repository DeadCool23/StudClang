#ifndef __ALLOCATE_H__
#define __ALLOCATE_H__

#include <stddef.h>

#include "errs.h"

/**
 * @brief Освобождение памяти выделенной под матрицу
 *
 * @param [in] matrix - матрица
 * @param [in] n - кол-во строк
 */
void matrix_free(double **matrix, size_t n);

/**
 * @brief Выделение памяти под матрицу
 * @details Память при выделении не очищается
 *
 * @param [in] n - количество строк
 * @param [in] m - количество столбцов
 * @return матрица
 */
double **matrix_alloc(size_t n, size_t m);
/**
 * @brief Выделение памяти под матрицу
 * @details Память при выделении очищается
 *
 * @param [in] n - количество строк
 * @param [in] m - количество столбцов
 * @return матрица
 */
double **matrix_calloc(size_t n, size_t m);

#endif  //__ALLOCATE_H__
