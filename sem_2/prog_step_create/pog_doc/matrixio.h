/**
 * @file matrixio.h
 * @author Нисуев Нису ИУ7-22Б
 * @brief Ввод элементов матрицы
 */

#ifndef MATRIXIO_H
#define MATRIXIO_H

#include <stddef.h>

/**
 * @def N
 * Максимальное кол-во строк матрицы
 * @def M 
 * Максимальное кол-во столбцов матрицы
*/
#define N 10
#define M 10

/*!
 * @fn int matrix_els(int matrix[][M], int n, int m)
 * @brief Функция ввода элементов матрицы
 * 
 * @param[out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 * @return Код ошибки
 */
int matrix_els(int matrix[][M], int n, int m);

#endif
