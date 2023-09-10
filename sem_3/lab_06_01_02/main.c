#include <stdio.h>

#include "errs.h"
#include "subj_arr.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return ERR_ARGS;

    err_t err = OK;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return ERR_FILE;

    subject_t subjs[N];
    size_t subjs_cnt = 0;
    err = subjects_read(file, subjs, N, &subjs_cnt);
    if (!err)
        err = subjects_print_by_option(stdout, subjs, subjs_cnt, argc == 2 ? TO_SORT : argv[2]);
    fclose(file);
    return err;
}
