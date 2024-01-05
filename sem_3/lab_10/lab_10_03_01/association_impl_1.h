#ifndef __ASSOCIATION_IMPL_1__
#define __ASSOCIATION_IMPL_1__

#include "associative_array.h"

/// Ассоциация
typedef struct
{
    char *key; // Ключ
    int val; // Значение
} assoc_t;

/**
 * @brief Функция освобождения памяти из под одной ассоциации
 * 
 * @param [in, out] element - ассоциация
 */
void assoc_destroy(assoc_t *element);

/**
 * @brief Функция создания ассоциации
 * 
 * @param [out] element - ассоциация 
 * @param [in] key - ключ
 * @param [in] num - значение
 * @return Код ошибки 
 */
assoc_array_error_t assoc_create(assoc_t *element, const char *key, int num);

/**
 * @brief Функция перестановки ассоциаций
 * 
 * @param [in, out] fst - первая ассоциация
 * @param [in, out] scd - вторая ассоциация
 */
void assoc_swap(assoc_t *fst, assoc_t *scd);

#endif // __ASSOCIATION_IMPL_1__