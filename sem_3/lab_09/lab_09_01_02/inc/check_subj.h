#ifndef CHECK_SUBJ_H
#define CHECK_SUBJ_H

#include <check.h>
#include "subject.h"

/**
 * @brief Функция сравнения структур
 * 
 * @param [in] X - первая структура  
 * @param [in] Y - вторая структура
 * 
 * @return 0 если структуры одинаковы
 * @return 1 иначе
 */
int ck_assert_subj_eq(const subject_t *X, const subject_t *Y);

/**
 * @brief Тестирование функции инициализации структуры
 * @return Набор тестов
 */
Suite* subj_init_suite(void);
/**
 * @brief Тестирование функции копирования структуры
 * @return Набор тестов
 */
Suite* subj_cpy_suite(void);
/**
 * @brief Тестирование функции сравнения структур по плотности
 * @return Набор тестов
 */
Suite* subjs_cmp_suite(void);
/**
 * @brief Тестирование функции подсчета плотности структуры
 * @return Набор тестов
 */
Suite* subj_density_calc_suite(void);
/**
 * @brief Тестирование функции поиска подстроки в начале имени структуры
 * @return Набор тестов
 */
Suite* substr_search_in_name_suite(void);

#endif
