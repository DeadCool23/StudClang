#include "errs.h"
#include <stdlib.h>
#include <ctype.h>
#include "matrix_generator.h"

int check_arg(char *arg)
{
    for (size_t i = 0; arg[i] != '\0'; i++)
         if (!isdigit(arg[i]))
            return ERR_ARG;
    return OK;
}

int check_arg_range(char *arg, size_t *n)
{
    int n_tmp = atoi(arg);
    if (0 >= n_tmp || n_tmp > N)
        return ERR_ARG_RANGE;
    *n = (size_t)n_tmp;
    return OK;
}
