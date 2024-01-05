#include "sort.h"

#include <stdlib.h>

void swap(void *fst, void *scd, size_t size)
{
    char *cfst = fst, *cscd = scd;
    for (size_t i = 0; i < size; i++)
    {
        char tmp = *cfst;
        *(cfst++) = *cscd;
        *(cscd++) = tmp;
    }
}

int int_compare(const void *left, const void *right)
{
    return *(int *)left - *(int *)right;
}

void mysort(void *arr, size_t num, size_t width, compare_t el_cmp)
{
    char *base = (char *)arr;

    for (char *pslow = base + width; pslow < base + num * width; pslow += width)
        for (char *pfast = pslow; pfast > base && el_cmp(pfast - width, pfast) > 0; pfast -= width)
            swap(pfast - width, pfast, width);
}
