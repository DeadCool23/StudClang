#include "check_math.h"

#include "allocate.h"
#include "check_process.h"

void ck_assert_matrix_double_eq(double **X, double **Y, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            ck_assert_double_eq_tol(X[i][j], Y[i][j], EPS);
}

// Тестирование sum
//-----------------------------------------

// Размеры матриц не совпадают
/// @def N - кол-во строк и столбцов первой и второй матрицы соответственно
/// @def M - кол-во столбцов и строк первой и второй матрицы соответственно
START_TEST(test_non_matching_sizes) {
#define N 2
#define M 3
    double a[N][M] = {{1, 2, 3}, {1, 2, 3}};
    double b[M][N] = {{1, 2}, {1, 2}, {1, 2}};
    double *pa[N] = {a[0], a[1]};
    double *pb[M] = {b[0], b[1], b[2]};
    matrix_t sa = {.rows = N, .cols = M, .matrix = pa};
    matrix_t sb = {.rows = M, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&sa, &sb, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Размеры квадратных матриц не совпадают
/// @def N - размер малой квадратной матрицы
START_TEST(test_non_matching_square_sizes) {
#define N 2
    double a[N][N] = {{1, 2}, {1, 2}};
    double b[N + 1][N + 1] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N + 1] = {b[0], b[1], b[2]};
    matrix_t sa = {.rows = N, .cols = N, .matrix = pa};
    matrix_t sb = {.rows = N + 1, .cols = N + 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&sa, &sb, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Попытка сложения квадратной и прямоугольной матриц
/// @def N - размер квадратной матрицы
START_TEST(test_non_matching_square_size) {
#define N 2
    double a[N][N] = {{1, 2}, {1, 2}};
    double b[N][N + 1] = {{1, 2, 3}, {1, 2, 3}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N] = {b[0], b[1]};
    matrix_t sa = {.rows = N, .cols = N, .matrix = pa};
    matrix_t sb = {.rows = N, .cols = N + 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&sa, &sb, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Сумма матриц первых порядков
// @def N - размер квадратных матриц слагаемых первого порядка
START_TEST(sum_of_first_ord_matrices) {
#define N 1
    double a[N][N] = {{1}};
    double b[N][N] = {{3}};
    double *pa[N] = {a[0]};
    double *pb[N] = {b[0]};
    matrix_t sa = {.rows = N, .cols = N, .matrix = pa};
    matrix_t sb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&sa, &sb, &res);

    double real[N][N] = {{4}};
    double *preal[N] = {real[0]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Сумма квадратных матриц
// @def N - размер квадратных матриц слагаемых
START_TEST(sum_of_square_matrices) {
#define N 2
    double a[N][N] = {{1, 2}, {3, 4}};
    double b[N][N] = {{0, 0}, {0, 0}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&ma, &mb, &res);

    double real[N][N] = {{1, 2}, {3, 4}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Сумма прямоугольных матриц
// @def N - кол-во строк квадратных матриц слагаемых
// @def M - кол-во столбцов квадратных матриц слагаемых
START_TEST(sum_of_rectangular_matrices) {
#define N 3
#define M 2
    double a[N][M] = {{1, 2}, {3, 4}, {5, 6}};
    double b[N][M] = {{10, 11}, {12, 13}, {14, 15}};
    double *pa[N] = {a[0], a[1], a[2]};
    double *pb[N] = {b[0], b[1], b[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = M, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&ma, &mb, &res);

    double real[N][M] = {{11, 13}, {15, 17}, {19, 21}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, M);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Сумма матриц-столбцов
// @def N - кол-во строк квадратных матриц слагаемых
START_TEST(sum_of_column_matrices) {
#define N 3
    double a[N][1] = {{1}, {2}, {3}};
    double b[N][1] = {{4}, {5}, {6}};
    double *pa[N] = {a[0], a[1], a[2]};
    double *pb[N] = {b[0], b[1], b[2]};
    matrix_t ma = {.rows = N, .cols = 1, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&ma, &mb, &res);

    double real[N][1] = {{5}, {7}, {9}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Сумма матриц-строк
// @def M - кол-во столбцов квадратных матриц слагаемых
START_TEST(sum_of_row_matrices) {
#define M 3
    double a[1][M] = {{1, 2, 3}};
    double b[1][M] = {{4, 5, 6}};
    double *pa[1] = {a[0]};
    double *pb[1] = {b[0]};
    matrix_t ma = {.rows = 1, .cols = M, .matrix = pa};
    matrix_t mb = {.rows = 1, .cols = M, .matrix = pb};

    matrix_t res;
    err_t err = matrix_sum(&ma, &mb, &res);

    double real[1][M] = {{5, 7, 9}};
    double *preal[1] = {real[0]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, 1);
    ck_assert_int_eq(res.cols, M);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef M
} END_TEST

Suite* sum_suite(void) {
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n___SUM___");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, test_non_matching_sizes);
    tcase_add_test(tc_neg, test_non_matching_square_sizes);
    tcase_add_test(tc_neg, test_non_matching_square_size);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, sum_of_first_ord_matrices);
    tcase_add_test(tc_pos, sum_of_square_matrices);
    tcase_add_test(tc_pos, sum_of_rectangular_matrices);
    tcase_add_test(tc_pos, sum_of_column_matrices);
    tcase_add_test(tc_pos, sum_of_row_matrices);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование mullt
//-----------------------------------------

// Некорректные размеры матриц для умножения
START_TEST(incorrect_size_matrix_mult) {
#define N 2
#define M 3
#define K 4
    double a[N][M] = {{1, 2, 3}, {4, 5, 6}};
    double b[K][M] = {{2, 0}, {1, 2, 3}, {0, 1, 2}};
    double *pa[N] = {a[0], a[1]};
    double *pb[K] = {b[0], b[1], b[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};
    matrix_t mb = {.rows = K, .cols = M + 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
#undef M
#undef K
} END_TEST

// Умножение матрицы-строки на квадратную матрицу
// @def N - кол-во столбцов матриц-строки
// @def N - размер квадратной матрицы
START_TEST(row_matrix_mult) {
#define N 2
    double a[1][N] = {{1, 2}};
    double b[N][N] = {{3, 4}, {5, 6}};
    double *pa[1] = {a[0]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = 1, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[1][N] = {{13, 16}};
    double *preal[1] = {real[0]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, 1);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Умножение квадратной матрицы на матрицу-столбец
// @def N - размер квадратной матрицы
// @def N - кол-во строк матриц-столбца
START_TEST(square_matrix_column_mult) {
#define N 2
    double a[N][N] = {{1, 2}, {3, 4}};
    double b[N][1] = {{2}, {1}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][1] = {{4}, {10}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Умножение матрицы-столбца на матрицу-строку
// @def N - размер матрицы-строки и матрицы-столбца
START_TEST(column_matrix_row_mult) {
#define N 2
    double a[1][N] = {{1, 2}};
    double b[N][1] = {{2}, {1}};
    double *pa[1] = {a[0]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = 1, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = 1, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[1][1] = {{4}};
    double *preal[1] = {real[0]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, 1);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Умножение квадратных матриц, одна из которых единичная
// @def N - размер квадратной матрицы
START_TEST(square_matrix_identity_mult) {
#define N 2
    double a[N][N] = {{1, 2}, {3, 4}};
    double b[N][N] = {{1, 0}, {0, 1}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][N] = {{1, 2}, {3, 4}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Умножение произвольных прямоугольных матриц с квадратным результатом
// @def N - кол-во строк и столбцов матрицы-множмого и матрицы-множителя соответсвенно
// @def M - кол-во столбцов и строк матрицы-множмого и матрицы-множителя соответсвенно
START_TEST(rectangular_matrix_mult_res_square) {
#define N 2
#define M 3
    double a[N][M] = {{1, 2, 3}, {4, 5, 6}};
    double b[M][N] = {{2, 0}, {1, 2}, {0, 1}};
    double *pa[N] = {a[0], a[1]};
    double *pb[M] = {b[0], b[1], b[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};
    matrix_t mb = {.rows = M, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][N] = {{4, 7}, {13, 16}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Умножение произвольных прямоугольных матриц с прямоугольным результатом
// @def N - кол-во строк матрицы-множимого
// @def M - кол-во столбцов матрицы-множимого
// @def M - размер матрицы-множителя
START_TEST(rectangular_matrix_mult_res_rectengular) {
#define N 2
#define M 3
    double a[N][M] = {{1, 2, 3}, {4, 5, 6}};
    double b[M][M] = {{2, 0, 3}, {1, 2, 3}, {0, 1, 3}};
    double *pa[N] = {a[0], a[1]};
    double *pb[M] = {b[0], b[1], b[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};
    matrix_t mb = {.rows = M, .cols = M, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][M] = {{4, 7, 18}, {13, 16, 45}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, M);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Умножение квадратных матриц первого порядка
// @def N - размер квадратных матриц первого порядка
START_TEST(first_ord_square_matrix_mult) {
#define N 1
    double a[N][N] = {{2}};
    double b[N][N] = {{3}};
    double *pa[N] = {a[0]};
    double *pb[N] = {b[0]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][N] = {{6}};
    double *preal[N] = {real[0]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Умножение двух квадратных матриц
// @def N - размер квадратных матриц
START_TEST(square_matrix_mult) {
#define N 2
    double a[N][N] = {{1, 2}, {3, 4}};
    double b[N][N] = {{2, 0}, {1, 2}};
    double *pa[N] = {a[0], a[1]};
    double *pb[N] = {b[0], b[1]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};
    matrix_t mb = {.rows = N, .cols = N, .matrix = pb};

    matrix_t res;
    err_t err = matrix_mult(&ma, &mb, &res);

    double real[N][N] = {{4, 4}, {10, 8}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, N);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
} END_TEST


Suite* mult_suite(void) {
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n___MULT___");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, incorrect_size_matrix_mult);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, row_matrix_mult);
    tcase_add_test(tc_pos, square_matrix_column_mult);
    tcase_add_test(tc_pos, column_matrix_row_mult);
    tcase_add_test(tc_pos, rectangular_matrix_mult_res_rectengular);
    tcase_add_test(tc_pos, square_matrix_identity_mult);
    tcase_add_test(tc_pos, rectangular_matrix_mult_res_square);
    tcase_add_test(tc_pos, first_ord_square_matrix_mult);
    tcase_add_test(tc_pos, square_matrix_mult);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование gauss
//-----------------------------------

// СЛАУ с бесконечным кол-вом решений
START_TEST(incorrect_squere_size_matrix_gauss) {
#define N 2
    double a[N][N] = {{1, 2}, {4, 5}};
    double *pa[N] = {a[0], a[1]};
    matrix_t ma = {.rows = N, .cols = N, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
} END_TEST

// Нулевая матрица
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(zero_matrix) {
#define N 2
#define M 3
    double a[N][M] = {{0, 0, 0}, {0, 0, 0}};
    double *pa[N] = {a[0], a[1]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Матрица состоящая из единиц
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(matrix_of_units) {
#define N 2
#define M 3
    double a[N][M] = {{1, 1, 1}, {1, 1, 1}};
    double *pa[N] = {a[0], a[1]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ не имеющая решений
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(infinity_ans_on_slau) {
#define N 2
#define M 3
    double a[N][M] = {{1, 2, 1}, {2, 4, 1}};
    double *pa[N] = {a[0], a[1]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    ck_assert_int_eq(err, ERR_MATH);

    if (!err)
        matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// Решенная СЛАУ 2-го порядка
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(identity_slau_matrix) {
#define N 2
#define M 3
    double a[N][M] = {{1, 0, 1}, {0, 1, 1}};
    double *pa[N] = {a[0], a[1]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[N][1] = {{1}, {1}};
    double *preal[N] = {real[0], real[1]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ имеющие одно решение 
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(slau_with_one_ans) {
#define N 3
#define M 4
    double a[N][M] = {{1, 2, 3, 3}, {3, 5, 7, 0}, {1, 3, 4, 1}};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[N][1] = {{-4.0}, {-13.0}, {11.0}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ имеющие одно решение без значений над главной диагональю
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(slau_zero_over_diagonal_with_one_ans) {
#define N 3
#define M 4
    double a[N][M] = {{1, 2, 3, 3}, {3, 5, 7, 0}, {1, 3, 4, 1}};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[N][1] = {{-4.0}, {-13.0}, {11.0}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ имеющие одно решение без значений под главной диагональю
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(slau_zero_below_diagonal_with_one_ans) {
#define N 3
#define M 4
    double a[N][M] = {{-1, 0, 0, -1}, {1, 1, 0, 2}, {1, 1, 1, 3},};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[N][1] = {{1.0}, {1.0}, {1.0}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ со значениями на главной диагонали
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
START_TEST(diagonal_slau_with_one_ans) {
#define N 3
#define M 4
    double a[N][M] = {{-5, 0, 0, -15}, {0, 3, 0, 9}, {0, 0, 2, 32},};
    double *pa[N] = {a[0], a[1], a[2]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[N][1] = {{3.0}, {3.0}, {16.0}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, N);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
} END_TEST

// СЛАУ 3-его порядка с лишней строкой
/// @def N - кол-во строк матрцы СЛАУ
/// @def M - кол-во столбцов матрицы СЛАУ
/// @def K - размер матрицы-столбца решений
START_TEST(slau_with_trash_line) {
#define N 4
#define M 4
#define K 3
    double a[N][M] = {{3, 2, -1, 10}, {2, -1, 3, 5}, {1, 4, -2, 8}, {1, 4, -2, 8}};
    double *pa[N] = {a[0], a[1], a[2], a[3]};
    matrix_t ma = {.rows = N, .cols = M, .matrix = pa};

    matrix_t res;
    err_t err = gauss(&ma, &res);

    double real[K][1] = {{12.0/5}, {43.0/25}, {16.0/25}};
    double *preal[N] = {real[0], real[1], real[2]};

    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(res.rows, K);
    ck_assert_int_eq(res.cols, 1);

    ck_assert_matrix_double_eq(res.matrix, preal, res.rows, res.cols);

    matrix_free(res.matrix, res.rows);
#undef N
#undef M
#undef K
} END_TEST

Suite* gauss_suite(void) {
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n___GAUSS___");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, incorrect_squere_size_matrix_gauss);
    tcase_add_test(tc_neg, zero_matrix);
    tcase_add_test(tc_neg, matrix_of_units);
    tcase_add_test(tc_neg, infinity_ans_on_slau);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, identity_slau_matrix);
    tcase_add_test(tc_pos, slau_with_one_ans);
    tcase_add_test(tc_pos, slau_zero_below_diagonal_with_one_ans);
    tcase_add_test(tc_pos, slau_zero_over_diagonal_with_one_ans);
    tcase_add_test(tc_pos, diagonal_slau_with_one_ans);
    tcase_add_test(tc_pos, slau_with_trash_line);

    suite_add_tcase(s, tc_pos);

    return s;
}
