#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H

#include <stddef.h>

/* N declared at compilation */
#ifndef N
#error N NOT DEFINED
#endif //N

typedef int matrix_t[N][N];

void matrix_generator(matrix_t fst, matrix_t scd, size_t n);

#endif // !MATRIX_GENERATOR_H

