#include "binwork.h"
#include "errs.h"
#include <stdbool.h>

int fb_get_by_pos(FILE *f, long pos, stud_t *stud)
{
    long cur = pos * sizeof(stud_t);
    if (fseek(f, cur, SEEK_SET) != 0)
        return ERR_FILE_WORK;
    if (fread(stud, sizeof(stud_t), 1, f) != 1)
        return ERR_FILE_WORK;
    return OK;
}

int fb_put_by_pos(FILE *f, long pos, const stud_t *stud)
{
    long cur = pos * sizeof(stud_t);
    if (fseek(f, cur, SEEK_SET) != 0)
        return ERR_FILE_WORK;
    if (fwrite(stud, sizeof(stud_t), 1, f) != 1)
        return ERR_FILE_WORK;
    return OK;
}

int bswap_studs(FILE *f, long ind_fst, long ind_scd, const stud_t *stud_fst, const stud_t *stud_scd)
{
    int err;
    err = fb_put_by_pos(f, ind_fst, stud_scd);
    if (err != OK)
        return err;
    err = fb_put_by_pos(f, ind_scd, stud_fst);
    if (err != OK)
        return err;
    return OK;
}

int get_stud_num(FILE *f, long *num_cnt)
{
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_FILE_WORK;
    if (ftell(f) % sizeof(stud_t))
        return ERR_FILE_WORK;
    *num_cnt = ftell(f) / sizeof(stud_t);
    if (*num_cnt <= 0)
        return ERR_FILE_WORK;
    if (fseek(f, 0, SEEK_SET) != 0)
        return ERR_FILE_WORK;
    return OK;
}

int fb_sort_by_fullname(FILE *f)
{
    int err = OK;
    long num_cnt;
    err = get_stud_num(f, &num_cnt);
    ERR_CHECK(err);
    long i, j;
    bool swapped = true;
    for (i = 0; i < num_cnt - 1 && swapped; i++)
    {
        swapped = false;
        stud_t stud_j, stud_j_1;
        for (j = 0; j < num_cnt - i - 1; j++)
        {
            err = fb_get_by_pos(f, j, &stud_j);
            ERR_CHECK(err);
            err = fb_get_by_pos(f, j + 1, &stud_j_1);
            ERR_CHECK(err);
            if (stud_cmp_by_fullname(&stud_j, &stud_j_1) > 0)
            {
                bswap_studs(f, j, j + 1, &stud_j, &stud_j_1);
                ERR_CHECK(err);
                swapped = true;
            }
        }
    }
    return err;
}

