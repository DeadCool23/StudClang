#ifndef CONDARR_H
#define CONDARR_H

#include "matrixio.h"
#include <stdbool.h>

/*!
 * Функция проверки столбца матрицы на убываемость
 * @param[in] matrix - матрица
 * @param[in] n, col_num - кол-во строк, номер стобца
 * @return значение логического типа
 */
bool order(int matrix[][M], size_t n, size_t col_num);

/*!
 * \brief Функция записывает в массив значения [0/1] в зависимости от условия
 * \details Условие: элементы столбца упорядочены по убыванию
 * @param[out] arr - массив
 * @param[in] matrix - матрица
 * @param[in] n, m - размерность матрицы
 */
void condarray(int arr[], int matrix[][M], size_t n, size_t m);

/*!
 * Процедура вывода массива на экран
 * @param[in] arr - массив
 * @param[in] n - длина массива
 */
void arr_output(const int arr[], size_t n);

#endif //CONDARR_H
