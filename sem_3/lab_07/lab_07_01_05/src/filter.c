#include "filter.h"

#include <stdlib.h>

int sum(const int *pbeg, const int *pend)
{
    int sum = 0;
    for (const int *pcur = pbeg; pcur != pend; pcur++)
        sum += *pcur;
    return sum;
}

err_t key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pe_src + 1 <= pb_src || !pe_src || !pb_src)
        return ERR_ARR;

    size_t count = 0;
    for (const int *pc_src = pb_src; pc_src < pe_src - 1; pc_src++)
        if (*pc_src > sum(pc_src + 1, pe_src))
            count++;

    if (count == 0)
        return ERR_ARR;

    *pb_dst = (int *)malloc(count * sizeof(int));
    if (*pb_dst == NULL)
        return ERR_MEM;
    *pe_dst = *pb_dst + count;

    size_t i = 0;
    for (const int *pc_src = pb_src; pc_src < pe_src - 1; pc_src++)
        if (*pc_src > sum(pc_src + 1, pe_src))
            *(*pb_dst + i++) = *pc_src;

    return OK;
}
