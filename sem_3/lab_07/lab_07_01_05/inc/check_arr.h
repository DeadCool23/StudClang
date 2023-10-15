#ifndef __CHECK_ARR_H__
#define __CHECK_ARR_H__

#include <stddef.h>

/**
 * @brief Функция сравнения элементов массивов целых чисел
 * 
 * @param [in] X - первый массив
 * @param [in] Y - второй массив
 * @param [in] size - кол-во сравниваемых элементов в массивах
 */
void ck_assert_int_arr_eq(const int *X, const int *Y, size_t size);

/**
 * @brief Функция сравнения элементов массивов чисел с плавающей точкой
 * 
 * @param [in] X - первый массив
 * @param [in] Y - второй массив
 * @param [in] size - кол-во сравниваемых элементов в массивах
 */
void ck_assert_double_arr_eq(const double *X, const double *Y, size_t size);

/**
 * @brief Функция сравнения элементов массивов целых чисел
 * 
 * @param [in] X - первый массив
 * @param [in] Y - второй массив
 * @param [in] size - кол-во сравниваемых элементов в массивах
 */
void ck_assert_char_arr_eq(const char *X, const char *Y, size_t size);

#endif //__CHECK_ARR_H__
