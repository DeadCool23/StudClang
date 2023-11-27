#ifndef CHECK_SUBJS_H
#define CHECK_SUBJS_H

#include <check.h>
#include "subject.h"

/**
 * @brief Функция сравнения массивов структур
 * 
 * @param [in] X - первый массив структур  
 * @param [in] Y - второй массив структур
 * @param [in] n - размер массивов
 * 
 * @return 0 если структуры одинаковы
 * @return 1 иначе
 */
int ck_assert_subjs_arr_eq(const subject_t *X, const subject_t *Y, size_t n);

/**
 * @brief Тестирование функции сортировки массива структур по возрастанию плотности
 * 
 * @return Набор тестов
 */
Suite* subjects_sort_by_density_suite(void);

#endif
