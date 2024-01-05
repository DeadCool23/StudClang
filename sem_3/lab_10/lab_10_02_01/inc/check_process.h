#ifndef __CHECK_PROCESS_H__
#define __CHECK_PROCESS_H__

#include <check.h>

#include "nomen.h"
#include "polinom.h"

/**
 * @brief Функция сравнения точек
 * 
 * @param [in] X - первая точка
 * @param [in] Y - вторая точка
 * @return =0 точки равны
 * @return =1 иначе
 */
int ck_assert_nomen_eq(nomen_t *X, nomen_t *Y);
/**
 * @brief Функция сравнения списков
 * 
 * @param [in] X - первый список
 * @param [in] Y - второй список
 * @return =0 спики равны
 * @return =1 иначе
 */
int ck_assert_polinom_eq(polinom_t *X, polinom_t *Y);

#endif // __CHECK_PROCESS_H__
