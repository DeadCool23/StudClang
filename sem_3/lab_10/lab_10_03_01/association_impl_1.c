#include "association_impl_1.h"

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

void assoc_destroy(assoc_t *element)
{
    free(element->key);
    element->key = NULL;
    element->val = 0;
}

assoc_array_error_t assoc_create(assoc_t *element, const char *key, int num)
{
    char *tmp_key = strdup(key);
    if (!tmp_key)
        return ASSOC_ARRAY_MEM;

    element->key = tmp_key;
    element->val = num;

    return ASSOC_ARRAY_OK;
}

/**
 * @brief Функция перестановки ассоциаций
 * 
 * @param [in, out] fst - первая ассоциация
 * @param [in, out] scd - вторая ассоциация
 */
void assoc_swap(assoc_t *fst, assoc_t *scd)
{
    assoc_t tmp = *fst;
    *fst = *scd;
    *scd = tmp;
}
