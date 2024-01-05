#include "association_impl_2.h"

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

void assoc_destroy(assoc_t *element)
{
    free(element->key);
    free(element);
}

assoc_array_error_t assoc_create(assoc_t **element, const char *key, int num)
{
    *element = malloc(sizeof(**element));
    if (!*element)
        return ASSOC_ARRAY_MEM;
    
    char *tmp_key = strdup(key);
    if (!tmp_key)
        return ASSOC_ARRAY_MEM;

    (*element)->key = tmp_key;
    (*element)->val = num;
    (*element)->next = NULL;

    return ASSOC_ARRAY_OK;
}