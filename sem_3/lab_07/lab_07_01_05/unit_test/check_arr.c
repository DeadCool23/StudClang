#include "check_arr.h"

#include <check.h>

void ck_assert_int_arr_eq(const int *X, const int *Y, size_t size) {
    for (size_t i = 0; i < size; i++)
        ck_assert_int_eq(X[i], Y[i]);
}

/**
 * @brief Функция сравнения элементов массивов чисел с плавающей точкой
 * 
 * @param [in] X - первый массив
 * @param [in] Y - второй массив
 * @param [in] size - кол-во сравниваемых элементов в массивах
 */
void ck_assert_double_arr_eq(const double *X, const double *Y, size_t size) {
    for (size_t i = 0; i < size; i++)
        ck_assert_double_eq(X[i], Y[i]);
}

/**
 * @brief Функция сравнения элементов массивов целых чисел
 * 
 * @param [in] X - первый массив
 * @param [in] Y - второй массив
 * @param [in] size - кол-во сравниваемых элементов в массивах
 */
void ck_assert_char_arr_eq(const char *X, const char *Y, size_t size) {
    for (size_t i = 0; i < size; i++)
        ck_assert_int_eq(X[i], Y[i]);
}
