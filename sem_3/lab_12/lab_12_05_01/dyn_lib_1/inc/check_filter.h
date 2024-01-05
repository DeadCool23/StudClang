#ifndef __TESTFILTER_H__
#define __TESTFILTER_H__

#include <check.h>
#include <stdlib.h>

/**
 * @brief Тестирование функции подсчета суммы элементов массива
 * 
 * @return Набор тестов
 */
Suite *sum_suite(void);
/**
 * @brief Тестирование функции получения размера отфильтрованного массива
 * 
 * @return Набор тестов
 */
Suite *key_len_suite(void);
/**
 * @brief Тестирование функции фильтрации
 * 
 * @return Набор тестов
 */
Suite *key_suite(void);

#endif  //__TESTFILTER_H__
