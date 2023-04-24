#ifndef MINODD_H
#define MINODD_H

#include "matrixio.h"

/*!
 * @def EVEN_BIT
 * Бит четности
 */
#define EVEN_BIT 1

/*!
 * Функция поиска минимального нечетного число, расположенного под главной диоганалью
 * @param[in] matrix  - матрица
 * @param[in] n - размерность квадратной матрицы
 * @param[out] min - минимальный элемент
 * @return Код ошибки
 */
int matrix_min_odd(int matrix[][N], size_t n, int *min);

#endif //MINODD_H
