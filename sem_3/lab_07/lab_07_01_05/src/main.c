#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrio.h"
#include "errs.h"
#include "filter.h"
#include "sort.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
        return ERR_ARGS;

    err_t err = OK;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return ERR_FILE;

    int *arr;
    size_t n = 0;
    err = fread_arr(file, &arr, &n);
    fclose(file);
    if (err)
        return err;

    if (argc == 4 && !strcmp(argv[3], "f"))
    {
        int *arr_filt = NULL, *arr_filt_end = NULL;
        err = key(arr, arr + n, &arr_filt, &arr_filt_end);
        free(arr);
        if (err)
        {
            free(arr_filt);
            return err;
        }
        n = (size_t)(arr_filt_end - arr_filt);
        arr = arr_filt;
    }
    else if (argc >= 4)
    {
        free(arr);
        return ERR_ARGS;
    }

    mysort(arr, n, sizeof(*arr), int_compare);

    file = fopen(argv[2], "w");
    if (file == NULL)
        return ERR_FILE;
    fprint_arr(file, arr, n);
    fclose(file);

    free(arr);
    return err;
}
