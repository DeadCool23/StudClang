#ifndef __CHECK_CREATE_DESTROY_H__
#define __CHECK_CREATE_DESTROY_H__

#include <check.h>

/**
 * @brief Функция проверки создания ассоциативного массива.
 * 
 * @return Набор тестов 
 */
Suite *assoc_array_create_suite(void);
/**
 * @brief Функция проверки удаления ассоциативного массива.
 * 
 * @return Набор тестов
 */
Suite *assoc_array_destoy_suite(void);

#endif // __CHECK_CREATE_DESTROY_H__