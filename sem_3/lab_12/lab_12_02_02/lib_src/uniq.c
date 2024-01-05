#include "uniq.h"
#include "errs.h"

#include <stdbool.h>

/**
 * @brief Проверка уникальности числа
 * 
 * @param [in] arr - массив чисел 
 * @param [in] n - размер массива
 * @param [in] num - число 
 * @return true число уникально
 * @return false иначе
 */
static bool is_uniq(const int *arr, size_t n, int num) {
    bool is_repeated = false;
    for (size_t i = 0; i < n && !is_repeated; i++)
        if (arr[i] == num)
            is_repeated = true;
    return !is_repeated;
}

/**
 * @brief Функция счета кол-ва первых вхождений чисел в массиые
 *
 * @param [in] arr - массив чисел
 * @param [in] n - размер массива
 * @return кол-во чисел
 */
static size_t uniq_cnt(const int *arr, size_t n) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (is_uniq(arr, i, arr[i]))
            count++;
    }
    return count;
}

int uniqcpy(const int *src, size_t src_size, int *dst, size_t *dst_size) {
    size_t real_dst_size = uniq_cnt(src, src_size);
    if (real_dst_size > *dst_size) {
        *dst_size = real_dst_size;
        return ERR_RANGE;
    }

    size_t index = 0;
    for (size_t i = 0; i < src_size; i++) {
        if (is_uniq(src, i, src[i]))
            dst[index++] = src[i];
    }
    *dst_size = index;
    return OK;
}
