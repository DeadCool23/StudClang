#ifndef REVPRIME_H
#define REVPRIME_H

#include "matrixio.h"
#include <stdbool.h>

/*!
 * Функция проверяет число на простоту
 * @param[in] n - число
 * @return Значение логического типа
 */
bool is_prime(int n);

/*!
 * Функция разворота массива
 * @param[out] arr - массив
 * @param[in] n - размер массива
 */
void rev_array(int arr[], size_t n);

/*!
 * \brief Функция запослнения массива элементами массива по определенному условию
 * \details Условие: элемент матрицы - простое число
 * @param[in] matrix - матрица
 * @param[in] n, m - размерность матрицы
 * @param[out] array_prime - массив простых чисел
 * @param[out] size_arr - длина массива
 * @return Код ошибки
 */
int add_prime(int matrix[][M], size_t n, size_t m, int array_prime[], size_t *size_arr);

/*!
 * Функция переворота простых элементов матрицы
 * @param[out] matrix - матрица
 * @param[in] n, m - размерность матрицы
 * @param[in] array_prime - массив простых элементов матрицы
 */
void rev_matrix_prime(int matrix[][M], size_t n, size_t m, const int array_prime[]);

#endif //REVPRIME_H
