#ifndef __ARRGEN_H__
#define __ARRGEN_H__

#include "errs.h"

#include <stddef.h>

#define RAND_GEN "random"
#define REVERSE_GEN "reversed"
#define SORTED_GEN "sorted"

/**
 * @brief Процедура генерации рандомного массива
 * 
 * @param [out] arr - массив
 * @param [in] n - размер массива
 */
void gen_rev_arr(int *arr, size_t n);
/**
 * @brief Процедура генерации отсортированного массива
 * 
 * @param [out] arr - массив
 * @param [in] n - размер массива
 */
void gen_sort_arr(int *arr, size_t n);
/**
 * @brief Процедура генерации убывающего массива
 * 
 * @param [out] arr - массив
 * @param [in] n - размер массива
 */
void gen_rand_arr(int *arr, size_t n);

/**
 * @brief ПФункция генерации массива по ключу
 * 
 * @param [in] key - ключ генерации
 * @param [out] arr - массив
 * @param [in] n - размер массива
 * 
 * @return Ошибка
 */
err_t gen_arr_by_key(int **arr, size_t n, char *key);

#endif //__ARRGEN_H__