#ifndef TRIANGLE_SWAP_H
#define TRIANGLE_SWAP_H

#include "matrixio.h"
#include <stddef.h>

/**
 * @brief Функция перестановки элементов строк
 *
 * @param[in,out] back_row - первая строка
 * @param[in,out] forth_row - вторая строка
 * @param[in] n - длина массива
 */
void rows_els_swap(int back_row[], int forth_row[], size_t n);

/**
 * @brief Функция перестановки элементов строк матрицы по определенному условию
 *
 * Условие:
 *
 * |* * * * *|    |$ $ $ $ $|
 * |. * * * .|    |. $ $ $ .|
 * |. . * . .| -> |. . * . .|
 * |. $ $ $ .|    |. * * * .|
 * |$ $ $ $ $|    |* * * * *|
 *
 * @param[in,out] matrix - матрица
 * @param[in] n - размер матрицы
 */
void triangle_up_down(int matrix[][M], size_t n);

#endif //TRIANGLE_SWAP_H
