#include "errs.h"
#include <stdio.h>

void calc_errs(int err)
{
    if (err == ERR_DATA)
        fprintf(stderr, "Data error\n");
    else
        fprintf(stderr, "Undefined error\n");
}
