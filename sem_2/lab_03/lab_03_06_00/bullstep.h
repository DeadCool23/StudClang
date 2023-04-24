#ifndef BULLSTEP_H
#define BULLSTEP_H

#include "matrixio.h"

/*!
 * Функция заполняет матрицу «ходом быка»
 * @param[out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void bull_step(int matrix[][M], size_t n, size_t m);

#endif //BULLSTEP_H
