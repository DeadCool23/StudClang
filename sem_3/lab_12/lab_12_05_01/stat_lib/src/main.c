#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errs.h"
#include "sort.h"
#include "arrio.h"
#include "filter.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
        return ERR_ARGS;

    err_t err = OK;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return ERR_FILE;

    size_t n = 0;
    int *arr = NULL;
    err = fcnt_arr_els(file, &n);
    rewind(file);
    if (!err && n > 0) {
        arr = malloc(n * sizeof(*arr));
        if (!arr)
            err = ERR_MEM;
        if (!err)
            err = fread_els_in_arr(file, arr, arr + n);
    } else
        err = ERR_IO;
    
    fclose(file);
    if (!err)
    {
        if (argc == 4 && !strcmp(argv[3], "f"))
        {
            int *arr_filt = NULL;
            size_t n_filt = key_len(arr, arr + n);
            if (!n_filt)
                err = ERR_ARR;
            else
                arr_filt = malloc(n_filt * sizeof(*arr_filt));

            if (!arr_filt)
                err = ERR_MEM;
            else
                err = key(arr, arr + n, arr_filt, n_filt);
            
            if (!err)
            {
                n = n_filt;
                free(arr);
                arr = arr_filt;
            }
            else
                free(arr_filt);
        }
        else if (argc >= 4)
            err = ERR_ARGS;

        if (!err)
        {
            mysort(arr, n, sizeof(*arr), int_compare);

            file = fopen(argv[2], "w");
            if (file == NULL)
                err = ERR_FILE;
            if (!err)
            {
                fprint_arr(file, arr, arr + n);
                fclose(file);
            }
        }
    }
    free(arr);
    return err;
}
