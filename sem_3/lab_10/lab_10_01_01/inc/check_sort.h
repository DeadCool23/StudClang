#ifndef __CHECH_SORT_H__
#define __CHECH_SORT_H__

#include <check.h>

/**
 * @brief Функция тестирования вставки элемента в отсортированный список
 * 
 * @return Набор тестов
 */
Suite *sorted_insert_suite(void);
/**
 * @brief Функция тестирования сортировки односвязного списка
 * 
 * @return Набор тестов
 */
Suite *sort_suite(void);

#endif // __CHECH_SORT_H__
