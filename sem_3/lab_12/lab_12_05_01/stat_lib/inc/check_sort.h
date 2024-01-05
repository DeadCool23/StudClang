#ifndef __TESTSORT_H__
#define __TESTSORT_H__

#include <check.h>

#include "sort.h"

/**
 * @brief Тестирование функции сравнения чисел с плавающей точкой
 * 
 * @return Набор тестов
 */
Suite *double_compare_suite(void);
/**
 * @brief Тестирование функции сравнения символов
 * 
 * @return Набор тестов
 */
Suite *char_compare_suite(void);
/**
 * @brief Тестирование функции сравнения целых чисел
 * 
 * @return Набор тестов
 */
Suite *int_compare_suite(void);
/**
 * @brief Тестирование функции сортировки
 * 
 * @return Набор тестов
 */
Suite *mysort_suite(void);

/**
 * @brief Сравнение чисел с плавающей точкой
 * 
 * @param [in] left - левое  число
 * @param [in] right - правое число
 * @return < 0 если правое число больше
 * @return = 0 если числа равны
 * @return > 0 если левое число больше
 */
int double_compare(const void *left, const void *right);
/**
 * @brief Сравнение символ с плавающей точкой
 * 
 * @param [in] left - левое  символ
 * @param [in] right - правое символ
 * @return < 0 если правое символ больше
 * @return = 0 если числа равны
 * @return > 0 если левое символ больше
 */
int char_compare(const void *left, const void *right);

#endif  //__TESTSORT_H__
