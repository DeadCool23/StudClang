#include "binwork.h"
#include "errs.h"
#include "numswork.h"
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

int fb_write_nums(FILE *f, size_t cnt)
{
    srand(time(NULL));
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_FILE_WORK;
    for (size_t i = 0; i < cnt; i++)
    {
        int32_t num = num_generate();
        if (fwrite(&num, sizeof(int32_t), 1, f) != 1)
            return ERR_FILE_WORK;
    }
    return OK;
}

int fb_print(FILE *f)
{
    size_t i = 0;
    int32_t prt_num;
    while (fread(&prt_num, sizeof(int32_t), 1, f))
    {
        printf("%" PRId32 "\n", prt_num);
        i++;
    }
    if (i == 0)
        return ERR_EMPTY_FILE;
    return OK;
}

int fb_sort(FILE *f)
{
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_FILE_WORK;
    if (ftell(f) % sizeof(int32_t))
        return ERR_FILE_WORK;
    long num_cnt = ftell(f) / sizeof(int32_t);
    if (num_cnt < 0)
        return ERR_FILE_WORK;
    if (num_cnt == 0)
        return ERR_EMPTY_FILE;
    if (fseek(f, 0, SEEK_SET) != 0)
        return ERR_FILE_WORK;

    int err = OK;
    long i, j;
    bool swapped = true;
    for (i = 0; i < num_cnt - 1 && swapped; i++)
    {
        swapped = false;
        int32_t num_j, num_j_1;
        for (j = 0; j < num_cnt - i - 1; j++)
        {
            err = get_number_by_pos(f, j, &num_j);
            ERR_CHECK(err);
            err = get_number_by_pos(f, j + 1, &num_j_1);
            ERR_CHECK(err);
            if (num_j > num_j_1)
            {
                bswap_nums(f, j, j + 1, num_j, num_j_1);
                ERR_CHECK(err);
                swapped = true;
            }
        }
    }

    return OK;
}
