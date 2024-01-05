#include "associative_array.h"
#include "association_impl_2.h"

#define _GNU_SOURCE

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct assoc_array_type
{
    assoc_t *head; // Голова списка ассоциаций
};

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(*arr));
    if (arr)
        arr->head = NULL;
    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (!*arr)
        return;
    
    assoc_array_clear(*arr);
    
    free(*arr);
    *arr = NULL;
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    assoc_t *prev_assoc = NULL;
    for (assoc_t *iassoc = arr->head; iassoc; iassoc = iassoc->next)
    {
        prev_assoc = iassoc;
        if (!strcmp(key, iassoc->key))
            return ASSOC_ARRAY_KEY_EXISTS;
    }

    assoc_t *new_assoc = NULL;
    assoc_array_error_t err = ASSOC_ARRAY_OK;
    if ((err = assoc_create(&new_assoc, key, num)))
        return err;

    if (prev_assoc)
        prev_assoc->next = new_assoc;
    else
        arr->head = new_assoc;
            
    return ASSOC_ARRAY_OK; 
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    bool is_finded = false;

    if (!key || !strlen(key) || !arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (assoc_t *iassoc = arr->head; iassoc && !is_finded; iassoc = iassoc->next)
    {
        if (!strcmp(key, iassoc->key))
        {
            *num = &iassoc->val;
            is_finded = true;
        }
    }

    return is_finded ? ASSOC_ARRAY_OK : ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    bool is_found = false;

    if (!key || !strlen(key) || !arr)
        return ASSOC_ARRAY_INVALID_PARAM;

    assoc_t *prev_assoc = NULL;
    for (assoc_t *iassoc = arr->head; iassoc && !is_found;)
    {
        if (!strcmp(key, iassoc->key))
        {
            assoc_t *del_assoc = iassoc;
            iassoc = iassoc->next;

            if (prev_assoc)
            {
                prev_assoc->next = iassoc;
                prev_assoc = prev_assoc->next;
            }
            else
            {
                arr->head = iassoc;
                prev_assoc = arr->head;
            }

            assoc_destroy(del_assoc);
            is_found = true;
        }
        else
        {
            prev_assoc = iassoc;
            iassoc = iassoc->next;
        }
    }

    return !is_found ? ASSOC_ARRAY_NOT_FOUND : ASSOC_ARRAY_OK;
}


assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    for (assoc_t *iassoc = arr->head; iassoc;)
    {
        assoc_t *del_assoc = iassoc;
        iassoc = iassoc->next;
        assoc_destroy(del_assoc);
    }
    arr->head = NULL;

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
        return ASSOC_ARRAY_INVALID_PARAM;

    for (assoc_t *iassoc = arr->head; iassoc; iassoc = iassoc->next)
        action(iassoc->key, &iassoc->val, param);
    
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->head->val;
    char *min_key = arr->head->key;
    for (assoc_t *iassoc = arr->head->next; iassoc; iassoc = iassoc->next)
    {
        if (strcmp(min_key, iassoc->key) > 0)
        {
            min_key = iassoc->key;
            *num = &iassoc->val;
        }
    }

    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
        return ASSOC_ARRAY_INVALID_PARAM;
    
    if (!arr->head)
        return ASSOC_ARRAY_NOT_FOUND;

    *num = &arr->head->val;
    char *max_key = arr->head->key;
    for (assoc_t *iassoc = arr->head->next; iassoc; iassoc = iassoc->next)
    {
        if (strcmp(max_key, iassoc->key) < 0)
        {
            max_key = iassoc->key;
            *num = &iassoc->val;
        }
    }

    return ASSOC_ARRAY_OK;
}