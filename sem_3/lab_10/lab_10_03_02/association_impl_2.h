#ifndef __ASSOCIATION_IMPL_2__
#define __ASSOCIATION_IMPL_2__

#include "associative_array.h"

/// Ассоциация
typedef struct assoc
{
    char *key; // Ключ
    int val; // Значение
    struct assoc *next; // Следующая ассоциация
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
assoc_array_error_t assoc_create(assoc_t **element, const char *key, int num);

#endif // __ASSOCIATION_IMPL_2__