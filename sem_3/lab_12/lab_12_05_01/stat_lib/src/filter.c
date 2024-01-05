#include "filter.h"

#include <stdlib.h>

int sum(const int *pbeg, const int *pend)
{
    int sum = 0;
    for (const int *pcur = pbeg; pcur != pend; pcur++)
        sum += *pcur;
    return sum;
}

size_t key_len(const int *pb_src, const int *pe_src)
{
    size_t count = 0;
    if (pe_src + 1 <= pb_src || !pe_src || !pb_src)
        return count;

    int total_sum = sum(pb_src, pe_src);
    for (const int *pc_src = pb_src; pc_src < pe_src - 1; pc_src++)
        if (*pc_src > (total_sum -= *pc_src))
            count++;
    
    return count;
}

err_t key(const int *pb_src, const int *pe_src, int *pb_dst, size_t len)
{
    if (pe_src + 1 <= pb_src || !pe_src || !pb_src || !pb_dst || !len)
        return ERR_ARR;

    size_t i = 0;
    int total_sum = sum(pb_src, pe_src);
    for (const int *pc_src = pb_src; pc_src < pe_src - 1; pc_src++) {
        if (*pc_src > (total_sum -= *pc_src)) {
            if (i >= len)
                return ERR_ARR;
            *(pb_dst + i++) = *pc_src;
        }
    }

    return !i ? ERR_ARR : OK;
}
