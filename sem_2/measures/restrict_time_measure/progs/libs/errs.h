#ifndef ERRS_H
#define ERRS_H

#include <stddef.h>

#define OK 0
#define ERR_ARGS_CNT 1
#define ERR_ARG 2
#define ERR_ARG_RANGE 3

int check_arg(char *arg);

int check_arg_range(char *arg, size_t *n);

#endif // !ERRS_H
