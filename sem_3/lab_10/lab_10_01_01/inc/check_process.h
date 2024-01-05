#ifndef __CHECK_PROCESS_H__
#define __CHECK_PROCESS_H__

#include <check.h>

#include "node.h"
#include "point.h"

/**
 * @brief Функция сравнения точек
 * 
 * @param [in] X - первая точка
 * @param [in] Y - вторая точка
 * @return =0 точки равны
 * @return =1 иначе
 */
int ck_assert_point_eq(point_t *X, point_t *Y);
/**
 * @brief Функция сравнения списков
 * 
 * @param [in] X - первый список
 * @param [in] Y - второй список
 * @return =0 спики равны
 * @return =1 иначе
 */
int ck_assert_list_eq(list_t *X, list_t *Y);

#endif // __CHECK_PROCESS_H__
