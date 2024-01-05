#ifndef __CHECK_PROCESS_H__
#define __CHECK_PROCESS_H__

#include <check.h>

/**
 * @brief Функция тестирования сравнение точки с дистанцие до начала СК
 * 
 * @return Набор тестов
 */
Suite *dist_cmp_suite(void);
/**
 * @brief Функция тестирования сравнения точек
 * 
 * @return Набор тестов
 */
Suite *points_cmp_suite(void);

#endif // __CHECK_PROCESS_H__
