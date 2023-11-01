#ifndef __MATRIX_STRUCT__
#define __MATRIX_STRUCT__

#include <stddef.h>

typedef struct
{
    size_t rows;
    size_t cols;
    double **matrix;
} matrix_t;

#endif  //__MATRIX_STRUCT__

