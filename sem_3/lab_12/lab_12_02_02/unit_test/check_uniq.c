#include "check_uniq.h"

#include "errs.h"
#include "uniq.h"

// Изначально нулевой размер конечного массива
START_TEST(zero_dst_size) {
#define N 3
    int dst[N];
    size_t dst_len = 0;
    int src[N] = {1, 2, 3};
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, ERR_RANGE);
    ck_assert_int_eq(dst_len, N);
#undef N
} END_TEST

// Изначальный размер конечного массива меньше чем реальный
START_TEST(dst_size_less_then_real) {
#define N 3
    int dst[N];
    size_t dst_len = 2;
    int src[N] = {1, 2, 3};
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, ERR_RANGE);
    ck_assert_int_eq(dst_len, N);
#undef N
} END_TEST

// Исходный массив состоит из одного элемента
START_TEST(src_one_elem) {
#define N 1
    int dst[N];
    int etalon_dst[N] = { 1 };
    size_t dst_len = N;
    int src[N] = {1 };
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(dst_len, N);
    ck_assert_mem_eq(dst, etalon_dst, sizeof(*dst) * dst_len);
#undef N
} END_TEST

// Исходный массив без повторений
START_TEST(src_without_repeat) {
#define N 3
    int dst[N];
    int etalon_dst[N] = { 1, 2, 3 };
    size_t dst_len = N;
    int src[N] = {1, 2, 3 };
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(dst_len, N);
    ck_assert_mem_eq(dst, etalon_dst, sizeof(*dst) * dst_len);
#undef N
} END_TEST

// Исходный массив с повторениями подряд
START_TEST(src_with_repeat_neighbour) {
#define N 4
#define UNIQ_N 3
    int dst[UNIQ_N];
    int etalon_dst[UNIQ_N] = { 1, 2, 3 };
    size_t dst_len = UNIQ_N;
    int src[N] = {1, 2, 3, 3 };
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(dst_len, N - 1);
    ck_assert_mem_eq(dst, etalon_dst, sizeof(*dst) * dst_len);
#undef UNIQ_N
#undef N
} END_TEST

// Исходный массив с повторениями
START_TEST(src_with_repeats) {
#define N 7
#define UNIQ_N 4
    int dst[UNIQ_N];
    int etalon_dst[UNIQ_N] = { 1, 2, 3, 4 };
    size_t dst_len = UNIQ_N;
    int src[N] = {1, 2, 3, 3, 2, 1, 4 };
    int err = uniqcpy(src, N, dst, &dst_len);
    ck_assert_int_eq(err, OK);
    ck_assert_int_eq(dst_len, UNIQ_N);
    ck_assert_mem_eq(dst, etalon_dst, sizeof(*dst) * dst_len);
#undef UNIQ_N
#undef N
} END_TEST

Suite *uniqcpy_suite(void) {
    Suite *s;
    TCase *tests;

    s = suite_create("\nUNIQCPY");
    tests = tcase_create(" tests ");

    tcase_add_test(tests, zero_dst_size);
    tcase_add_test(tests, dst_size_less_then_real);

    tcase_add_test(tests, src_one_elem);
    tcase_add_test(tests, src_without_repeat);
    tcase_add_test(tests, src_with_repeat_neighbour);
    tcase_add_test(tests, src_with_repeats);

    suite_add_tcase(s, tests);

    return s;
}
