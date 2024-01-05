#ifndef __CHECK_ADD_DEL_H__
#define __CHECK_ADD_DEL_H__

#include <check.h>

/**
 * @brief Функция проверки вставки элементов в ассоциативный массив.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_insert_suite(void);
/**
 * @brief Функция проверки очистки ассоциативного массива.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_clear_suite(void);
/**
 * @brief Функция проверки удаления элементов из ассоциативного массива.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_remove_suite(void);

#endif // __CHECK_ADD_DEL_H__