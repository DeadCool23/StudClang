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
 * Функция ввода элементов матрицы
 * @param[out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 * @return Код ошибки
 */
int matrix_els(int matrix[][M], size_t n, size_t m);

/*!
 * Функция ввода квадратной матрицы и размерности матрицы
 * @param[out] matrix - матрица
 * @param[out] n, m - размерность матрицы
 * @return Код ошибки
 */
int square_matrix_input(int matrix[][M], size_t *n, size_t *m);

/*!
 * Процедура вывода матрицы
 * @param[in] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void square_matrix_output(int matrix[N][M], size_t n);

#endif //MATRIXIO_H
