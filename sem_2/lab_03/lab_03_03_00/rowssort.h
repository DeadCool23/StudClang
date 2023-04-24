#ifndef ROWSORT_H
#define ROWSORT_H

#include "matrixio.h"

/*!
 * Функция суммирования элементов строки матрицы
 * @param[in] row - строка
 * @param[in] n - длина строки
 * @return sum - сумма элементов строки
 */
int row_sum(const int row[], size_t n);

/*!
 * Функция перестановки строк местами
 * @param[out] matrix - матрица
 * @param[in] m - длина строки
 * @param[in] index - индекс перестанавливаемой строки
 */
void rows_swap(int matrix[][M], size_t index, size_t m);

/*!
 * \brief Функция сортировки строк матрицы по заданному условию
 *
 * \details Условие: по возрастанию суммы их элементов
 * \details Метод сортировки: пузырек с флагом(устойчивый алгоритм сортировки)
 * @param[in,out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void rows_sort(int matrix[][M], size_t n, size_t m);

#endif //ROWSORT_H
