#ifndef __CHECK_PROCESS__
#define __CHECK_PROCESS__

#include <check.h>

#include "process.h"

/**
 * @brief Модульное тестирование суммы матриц
 *
 * @return Набор тестов
 */
Suite* swap_rows_suite(void);
/**
 * @brief Модульное тестирование произведения матриц
 *
 * @return Набор тестов
 */
Suite* matrix_copy_suite(void);

#endif  //__CHECK_PROCESS__