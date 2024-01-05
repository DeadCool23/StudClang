#include "associative_array.h"
#include "association_impl_1.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STD_STEP 2

/// Тип ассоциативный массив: ключ - строка, значение - целое число.
struct assoc_array_type
{
    size_t size; // Размер ассоциативного массива
    size_t step; // Шаг увелечения
    size_t capacity; // Вместительность массива
    assoc_t *els; // Ассоциативный массив
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(*arr));
    if (!arr)
        return NULL;
    arr->els = NULL;
    arr->step = STD_STEP;
    arr->capacity = 0;
    arr->size = 0;
    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (!*arr)
        return;
    
    assoc_array_t array = *arr;
    assoc_array_clear(array);

    free(*arr);
    *arr = NULL;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (size_t i = 0; i < arr->size; i++)
        if (!strcmp(key, arr->els[i].key))
            return ASSOC_ARRAY_KEY_EXISTS;
    
    assoc_t tmp_assoc;
    assoc_array_error_t err = ASSOC_ARRAY_OK;
    if ((err = assoc_create(&tmp_assoc, key, num)))
        return err;

    if (!arr->capacity)
    {
        arr->capacity = 1;
        arr->els = malloc(sizeof(*arr->els));
        err = !arr->els ? ASSOC_ARRAY_MEM : err;
    }
    else if (arr->capacity == arr->size)
    {
        arr->capacity *= 2;
        assoc_t *ptmp = realloc(arr->els, arr->capacity * sizeof(*arr->els));
        arr->els = ptmp ? ptmp : arr->els;
        err = !ptmp ? ASSOC_ARRAY_MEM : err;
    }

    if (err)
    {
        assoc_destroy(&tmp_assoc);
        return err;
    }

    arr->els[arr->size++] = tmp_assoc;
    return ASSOC_ARRAY_OK; 
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    bool is_finded = false;

    if (!key || !strlen(key) || !arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (size_t i = 0; i < arr->size && !is_finded; i++)
    {
        if (!strcmp(key, arr->els[i].key))
        {
            *num = &arr->els[i].val;
            is_finded = true;
        }
    }

    return is_finded ? ASSOC_ARRAY_OK : ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    bool is_finded = false;

    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    for (size_t i = 0; i < arr->size && !is_finded; i++)
    {
        if (!strcmp(key, arr->els[i].key))
        {
            assoc_swap(&arr->els[i], &arr->els[--arr->size]);
            is_finded = true;
        }
    }

    if (!is_finded)
        return ASSOC_ARRAY_NOT_FOUND;

    assoc_destroy(&arr->els[arr->size]);
    assoc_array_error_t err = ASSOC_ARRAY_OK;
    if (arr->size < arr->capacity / (arr->step * arr->step))
    {
        arr->capacity /= 2;
        assoc_t *ptmp = realloc(arr->els, arr->capacity * sizeof(*arr->els));
        arr->els = ptmp ? ptmp : arr->els;
        err = !ptmp ? ASSOC_ARRAY_MEM : err;
    }

    if (err)
        return err;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    for (size_t i = 0; i < arr->size; i++)
        assoc_destroy(arr->els + i);

    free(arr->els);
    arr->capacity = 0;
    arr->els = NULL;
    arr->size = 0;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (size_t i = 0; i < arr->size; i++)
        action(arr->els[i].key, &arr->els[i].val, param);
    
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->size)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->els[0].val;
    char *min_key = arr->els[0].key;
    for (size_t i = 1; i < arr->size; i++)
    {
        if (strcmp(min_key, arr->els[i].key) > 0)
        {
            min_key = arr->els[i].key;
            *num = &arr->els[i].val;
        }
    }

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->size)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->els[0].val;
    char *max_key = arr->els[0].key;
    for (size_t i = 1; i < arr->size; i++)
    {
        if (strcmp(max_key, arr->els[i].key) < 0)
        {
            max_key = arr->els[i].key;
            *num = &arr->els[i].val;
        }
    }

    return ASSOC_ARRAY_OK;
}