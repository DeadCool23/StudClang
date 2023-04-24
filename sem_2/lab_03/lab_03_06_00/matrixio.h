#ifndef MATRIXIO_H
#define MATRIXIO_H

#include <stddef.h>

/*!
 * @def N
 * Максимальное кол-во строк матрицы
 * @def M
 * Максимальное кол-во столбцов матрицы
 */
#define N 10
#define M 10

/*!
 * Функция ввода размерности матрицы
 * @param[out] n - кол-во строк матрицы
 * @param[out] m - кол-во столбцов матрицы
 * @return Код ошибки
 */
int matrix_size(size_t *n, size_t *m);

/*!
 * Процедура вывода матрицы
 * @param[in] matrix
 * @param[in] n, m - размерность матрицы
 */
void matrix_output(int matrix[N][M], size_t n, size_t m);

#endif //MATRIXIO_H
