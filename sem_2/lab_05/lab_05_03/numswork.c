#include "numswork.h"
#include "errs.h"
#include <stdlib.h>

int32_t num_generate(void)
{
    return rand() % 2001 - 1000;
}

int get_number_by_pos(FILE *f, long pos, int *num)
{
    long cur = pos * sizeof(int32_t);
    if (fseek(f, cur, SEEK_SET) != 0)
        return ERR_FILE_WORK;
    if (fread(num, sizeof(int32_t), 1, f) != 1)
        return ERR_DATA;
    return OK;
}

int put_number_by_pos(FILE *f, long pos, int num)
{
    long cur = pos * sizeof(int32_t);
    if (fseek(f, cur, SEEK_SET) != 0)
        return ERR_FILE_WORK;
    if (fwrite(&num, sizeof(int32_t), 1, f) != 1)
        return ERR_DATA;
    return OK;
}

int bswap_nums(FILE *f, long ind_fst, long ind_scd, int32_t num_fst, int32_t num_scd)
{
    int err;
    err = put_number_by_pos(f, ind_fst, num_scd);
    if (err != OK)
        return err;
    err = put_number_by_pos(f, ind_scd, num_fst);
    if (err != OK)
        return err;
    return OK;
}
