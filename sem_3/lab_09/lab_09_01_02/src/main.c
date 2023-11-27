#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errs.h"
#include "subj_arr.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return ERR_ARGS;

    err_t err = OK;
    size_t subjs_cnt = 0;
    subject_t *subjs = NULL;
    err = subjects_create_ex(argv[1], &subjs, &subjs_cnt);

    if (!err)
    {
        if (argc == 2)
        {
            if (subjs_cnt > 1)
                subjects_sort_by_density(subjs, subjs_cnt, subjs_cmp);
            if (subjects_print_all(stdout, subjs, subjs_cnt))
                err = ERR_IO;
        }
        else if (argc == 3 && !strcmp(argv[2], "ALL"))
        {
            if (subjects_print_all(stdout, subjs, subjs_cnt))
                err = ERR_IO;
        }
        else
        {
            if (subjects_print_with_substr(stdout, subjs, subjs_cnt, argv[2]))
                err = ERR_IO;
        }
    }
    free_subjs(subjs, subjs_cnt);
    return err;
}
