#ifndef __FILTER_H__
#define __FILTER_H__

#include "errs.h"
#include <stddef.h>

/**
 * @brief Функция сложения всех элементов массива
 *
 * @param [in] pbeg - начало массива
 * @param [in] pend - конец массива
 * @return сумма
 */
int sum(const int *pbeg, const int *pend);

/**
 * @brief Функция получения размера отфильтрованного массива
 *
 * @param [in] pb_src - указатель на начало исходного массива
 * @param [in] pe_src - указатель на конец исходного массива
 * @return размер отфильтрованного массива 
 */
size_t key_len(const int *pb_src, const int *pe_src);
/**
 * @brief Функция фильтрации элементов изначального массива и запись отфильтрованных в новый массив
 * @details Поиск элементов которые больше суммы последующих элементов
 *
 * @param [in] pb_src - указатель на начало исходного массива
 * @param [in] pe_src - указатель на конец исходного массива
 * @param [out] pb_dst - указатель на начало нового массива
 * @param [in] len - размер отфильтрованного массива
 * @return Код ошибки
 */
err_t key(const int *pb_src, const int *pe_src, int *pb_dst, size_t len);

#endif  //__FILTER_H__
