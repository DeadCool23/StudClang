#ifndef __MATH_H__
#define __MATH_H__

#include "errs.h"
#include "matrix_struct.h"

#define EPS 1e-10
#define RES_MATRIX_COLS 1

/**
 * @brief Функция сложения двух матриц
 *
 * @param [in] fst - первая матрица слагаемое
 * @param [in] scd - вторая матрица слагаемое
 * @param [out] res - матрица результат
 * @return Код ошибки
 */
err_t matrix_sum(const matrix_t *fst, const matrix_t *scd, matrix_t *res);
/**
 * @brief Функция умножения двух матриц
 *
 * @param [in] fst - первая матрица множимое
 * @param [in] scd - вторая матрица множитель
 * @param [out] res - матрица результат
 * @return Код ошибки
 */
err_t matrix_mult(const matrix_t *fst, const matrix_t *scd, matrix_t *res);
/**
 * @brief Функция решения СЛАУ методом Гаусса
 * @details выбор ведущего элемента по столбцу
 *
 * @param [in] slau - СЛАУ
 * @param [out] res - Матрица-столбец ответов
 * @return err_t
 */
err_t gauss(const matrix_t *slau, matrix_t *res);

#endif  //__MATH_H__

