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
 * @param[in,out] back_row - 1-ая строка для перестановки
 * @param[in,out] forth_row - 2-ая строка для перестановки
 * @param[in] m - длина строки
 */
void rows_swap(int back_row[], int forth_row[], size_t m);

/*!
 * \brief Функция сортировки строк матрицы по заданному условию
 *
 * \details Условие: по возрастанию суммы их элементов
 * \details Метод сортировки: пузырек с флагом(устойчивый алгоритм сортировки)
 * @param[in,out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void rows_bubble_sort(int matrix[][M], size_t n, size_t m);

/*!
 * \brief Функция сортировки строк матрицы по заданному условию
 *
 * \details Условие: по возрастанию суммы их элементов
 * \details Метод сортировки: выбором
 * @param[in,out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void rows_selection_sort(int matrix[][M], size_t n, size_t m);

#endif //ROWSORT_H
