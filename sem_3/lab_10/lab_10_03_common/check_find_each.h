#ifndef __CHECK_FIND_EACH_H__
#define __CHECK_FIND_EACH_H__

#include <check.h>

/**
 * @brief Функция проверки поиска элементов в ассоциативном массиве.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_find_suite(void);
/**
 * @brief Функция проверки выполнения функции по отношению к элементам в ассоциативном массиве.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_each_suite(void);

#endif // __CHECK_FIND_EACH_H__