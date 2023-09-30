#include "arrio.h"

#include <stdlib.h>

err_t fcnt_arr_els(FILE *file, size_t *n)
{
    int tmp;
    while (fscanf(file, "%d", &tmp) == 1)
        (*n)++;
    return (feof(file) && *n) ? OK : ERR_IO;
}

err_t fread_els_in_arr(FILE *file, int *arr, size_t n)
{
    int *ptr_arr = arr;
    for (size_t i = 0; i < n; i++)
        if (fscanf(file, "%d", ptr_arr++) != 1)
            return ERR_IO;
    return OK;
}

err_t fread_arr(FILE *file, int **arr, size_t *n)
{
    *n = 0;
    err_t err = fcnt_arr_els(file, n);
    if (err)
        return err;
    *arr = (int *)malloc(*n * sizeof(**arr));
    if (*arr == NULL)
        return ERR_MEM;
    rewind(file);
    err = fread_els_in_arr(file, *arr, *n);
    if (err)
    {
        free(*arr);
        return err;
    }
    return err;
}

void fprint_arr(FILE *file, const int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%d ", *(arr + i));
}
