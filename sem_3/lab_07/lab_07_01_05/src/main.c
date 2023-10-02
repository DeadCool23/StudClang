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

    size_t n = 0;
    int *arr = NULL;
    err = fread_arr(file, &arr, &n);
    fclose(file);
    if (err) goto END;

    if (argc == 4 && !strcmp(argv[3], "f")) {
        int *arr_filt = NULL, *arr_filt_end = NULL;
        err = key(arr, arr + n, &arr_filt, &arr_filt_end);
        free(arr);
        n = (size_t)(arr_filt_end - arr_filt);
        arr = arr_filt;
        if (err)
            goto END;
    } else if (argc >= 4) {
        err = ERR_ARGS;
        goto END;
    }

    mysort(arr, n, sizeof(*arr), int_compare);

    file = fopen(argv[2], "w");
    if (file == NULL) {
        err = ERR_FILE;
        goto END;
    }
    fprint_arr(file, arr, n);
    fclose(file);

    END:
    free(arr);
    return err;
}
