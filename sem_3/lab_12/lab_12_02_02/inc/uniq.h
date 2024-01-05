#ifndef __UNIQ_H__
#define __UNIQ_H__

#include <stddef.h>

/**
 * @brief Функция копирования первых вхождений элементов из одного массива в друго
 * 
 * @param [in] src - исходный массив
 * @param [in] src_size - размер исходного массива
 * @param [out] dst - получаемый массив
 * @param [in, out] dst_size - размер получаемого массива
 * @return код ошибки 
 */
int uniqcpy(const int *src, size_t src_size, int *dst, size_t *dst_size);

#endif // __UNIQ_H__