#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include <stddef.h>

/* N declared at compilation */
#ifndef N
#error N NOT DEFINED
#endif //N

/**
 * @typedef matrix_t
 * Тип матрицы 
 */
typedef int matrix_t[N][N];

/**
 * @brief Функция генерации 2-ух матриц
 * @param[out] fst - первая матрица
 * @param[out] scd - вторая матрица
 * @param[in] n - размерность матриц
 */
void matrix_generator(matrix_t fst, matrix_t scd, size_t n);

#endif // !MATRIX_GENERATOR_H

