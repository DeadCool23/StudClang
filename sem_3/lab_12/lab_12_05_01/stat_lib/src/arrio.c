#include "arrio.h"

#include <stdlib.h>

err_t fcnt_arr_els(FILE *file, size_t *n)
{
    int tmp;
    while (fscanf(file, "%d", &tmp) == 1)
        (*n)++;
    return feof(file) ? OK : ERR_IO;
}

err_t fread_els_in_arr(FILE *file, int *arr_beg, int *arr_end)
{
    for (int *pcur = arr_beg; pcur < arr_end; pcur++)
        if (fscanf(file, "%d", pcur) != 1)
            return ERR_IO;
    return OK;
}


void fprint_arr(FILE *file, const int *arr_beg, int *arr_end)
{
    for (const int *pcur = arr_beg; pcur < arr_end; pcur++)
        fprintf(file, "%d ", *(pcur));
}
