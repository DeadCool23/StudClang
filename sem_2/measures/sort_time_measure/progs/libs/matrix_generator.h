#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include <stddef.h>

#ifndef N
#error N NOT DECLARED
#endif // !N

typedef int arr_t[N];

void random_matrix(size_t n, int *arr);

void sorted_matrix(size_t n, int *arr);

#endif //MATRIX_GENERATOR_H
