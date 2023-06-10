#include "errs.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int check_file(const char *filename)
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
        return ERR_FILE;
    return OK;
}

int check_num(const char *num_str, size_t *number)
{
    char *end;
    long num_check = strtol(num_str, &end, 10);
    if (num_check == LONG_MAX || num_check == LONG_MIN)
        return ERR_NUM_PARAM;
    if (num_check <= 0)
        return ERR_NUM_RANGE;
    *number = num_check;
    return OK;
}
