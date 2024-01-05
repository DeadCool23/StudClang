#ifndef __CHECK_POLINOM_H__
#define __CHECK_POLINOM_H__

#include <check.h>

/**
 * @brief Функция тестирования функции val
 * 
 * @return Набор тестов
 */
Suite *val_suite(void);
/**
 * @brief Функция тестирования функции ddx
 * 
 * @return Набор тестов
 */
Suite *ddx_suite(void);
/**
 * @brief Функция тестирования функции sum
 * 
 * @return Набор тестов
 */
Suite *sum_suite(void);
/**
 * @brief Функция тестирования функции dvd
 * 
 * @return Набор тестов
 */
Suite *dvd_suite(void);

#endif // __CHECK_POLINOM_H__
