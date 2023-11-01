#include "check_process.h"

#include "allocate.h"
#include "check_math.h"

// Тестирование swap_rows
//---------------------------------------------------
/// @def N - кол-во строк матрцы
/// @def M - кол-во столбцов матрицы
START_TEST(check_swap) {
#define N 3
#define M 4
    double a[N][M] = {{-5, 0, 0, -15}, {0, 3, 0, 9}, {0, 0, 2, 32}};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    swap_rows(ma.matrix, 1, 0);

    double real[N][M] = {{0, 3, 0, 9}, {-5, 0, 0, -15}, {0, 0, 2, 32}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_matrix_double_eq(ma.matrix, preal, N, M); 
    
#undef N
#undef M
} END_TEST

Suite *swap_rows_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SWAP_ROWS___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, check_swap);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование marixcpu
//---------------------------------------------------
/// @def N - кол-во строк матрцы
/// @def M - кол-во столбцов матрицы
START_TEST(check_copy) {
#define N 3
#define M 4
    double a[N][M] = {{-5, 0, 0, -15}, {0, 3, 0, 9}, {0, 0, 2, 32}};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    double **res = matrix_alloc(N, M);
    if (res) {
        matrix_copy(res, &ma);

        double real[N][M] = {{-5, 0, 0, -15}, {0, 3, 0, 9}, {0, 0, 2, 32}};
        double *preal[N] = {real[0], real[1], real[2]};

        ck_assert_matrix_double_eq(ma.matrix, preal, N, M);

        matrix_free(res, N);
    } else
        ck_assert_ptr_null(res);
#undef N
#undef M
} END_TEST


Suite* matrix_copy_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___MATRIX_COPY___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, check_copy);

    suite_add_tcase(s, tc_pos);

    return s;
}