#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include <stddef.h>

/**
 * @def N
 * Максимальная длинна массива
 */
#ifndef N
#error N NOT DECLARED
#endif // !N

/**
 * @typedef arr_t
 * тип одномерного массива длиной N
 */
typedef int arr_t[N];

/**
 * @brief генерация рандомного массива
 * 
 * @param[in] n - длинна массива
 * @param[out] arr - массив 
 */
void random_matrix(size_t n, int *arr);

/**
 * @brief генерация отсортированного массива
 * 
 * @param[in] n - длинна массива
 * @param[out] arr - массив 
 */
void sorted_matrix(size_t n, int *arr);

#endif //MATRIX_GENERATOR_H
