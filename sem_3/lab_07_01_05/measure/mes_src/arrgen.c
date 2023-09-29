#include "arrgen.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void gen_rev_arr(int *arr, size_t n)
{
    for (ssize_t i = n - 1; i >= 0; i--)
        arr[i] = i;
}

void gen_sort_arr(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        arr[i] = i;
}

void gen_rand_arr(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        arr[i] = rand() % (n + 1) - 1;
}

err_t gen_arr_by_key(int **arr, size_t n, char *key)
{
    *arr = malloc(n * sizeof(**arr));
    if (!(*arr))
        return ERR_MEM; 
    if (!strcmp(key, SORTED_GEN))
        gen_sort_arr(*arr, n);
    else if (!strcmp(key, REVERSE_GEN))
        gen_rev_arr(*arr, n);
    else if (!strcmp(key, RAND_GEN))
        gen_rand_arr(*arr, n);
    else
        return ERR_KEY;
    return OK;
}