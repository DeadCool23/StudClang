#ifndef GETDATA_H
#define GETDATA_H

#include <stdio.h>
#include <stddef.h>

#include "errs.h"
#include "sort.h"

typedef void (*sort_t)(void (*), size_t, size_t, compare_t);

/**
 * @brief Функция получения времени работы сортировкиопределенного массива
 * 
 * @param [in] sort - Функция сортировки
 * @param [in] arr - массив
 * @param [in] n - кол-во элементов
 * @return Получение времени сортировки
 */
unsigned long long get_sort_time(sort_t sort, int *arr, size_t n);
/**
 * @brief 
 * 
 * @param [out] file - файл записи замеров
 * @param [in] sort - функция сортировки
 * @param [in] arr - массив
 * @param [in] n - размер массива
 * @return Ошибка 
 */
err_t add_sort_time(FILE *file, sort_t sort, int *arr, size_t n);

/**
 * @brief Функция записи замеров времени работы сортировок массивов определенного типа
 * @details Замеры сортировок mysort, qsort
 * @details Замеряются массивы линной до 500
 * 
 * @param [in] key - Ключ типа массива
 * @return Ошибка 
 */
err_t get_mes_res(char *key);

#endif //GETDATA_H