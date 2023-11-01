#ifndef __CHECK_MATH__
#define __CHECK_MATH__

#include <check.h>

#include "matrix_math.h"

/**
 * @brief Функция сравнения матриц
 * 
 * @param [in] X - первая матрица
 * @param [in] Y - вторая матрица
 * @param [in] rows - кол-во строк
 * @param [in] cols - кол-во столбцов
 */
void ck_assert_matrix_double_eq(double **X, double **Y, size_t rows, size_t cols);

/**
 * @brief Модульное тестирование суммы матриц
 *
 * @return Набор тестов
 */
Suite* sum_suite(void);
/**
 * @brief Модульное тестирование произведения матриц
 *
 * @return Набор тестов
 */
Suite* mult_suite(void);
/**
 * @brief Модульное тестирование метода Гаусса
 *
 * @return Набор тестов
 */
Suite* gauss_suite(void);

#endif  //__CHECK_MATH__