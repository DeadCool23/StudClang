#ifndef __CHECK_MIN_MAX_H__
#define __CHECK_MIN_MAX_H__

#include <check.h>

/**
 * @brief Функция проверки поиска минимального элемента в ассоциативном массиве.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_min_suite(void);
/**
 * @brief Функция проверки поиска максимального элемента в ассоциативном массиве.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_max_suite(void);

#endif // __CHECK_MIN_MAX_H__