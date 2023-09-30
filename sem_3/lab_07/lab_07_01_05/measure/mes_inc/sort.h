#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>

#include "errs.h"

/// @brief Тип функции сравнения двух элементов
typedef int (*compare_t)(const void *, const void *);

/**
 * @brief Функция перестановки элементов массива
 *
 * @param [in, out] fst - первый элемент
 * @param [in, out] scd - второй элемент
 * @param [in] size - размер типа данных массива в байтах
 * @return Ошибки
 */
void swap(void *fst, void *scd, size_t size);

/**
 * @brief Функция сравнения целых чисел
 *
 * @param [in] left - левое целое число
 * @param [in] right - правое целое число
 * @return < 0 если правое число больше
 * @return = 0 если числа равны
 * @return > 0 если левое число больше
 */
int int_compare(const void *left, const void *right);

/**
 * @brief Сортировка массива неизвестного типа данных
 * @details Сортировка простыми вставками
 * @details Устойчивый алгоритм сортировки
 *
 * @param [in, out] arr - массив
 * @param [in] num - размер массива
 * @param [in] size - размер типа данных массива в байтах
 * @param [in] cmp - функция сравнения элементов массива
 */
void mysort(void *arr, size_t num, size_t size, compare_t el_cmp);

#endif  //__SORT_H__
