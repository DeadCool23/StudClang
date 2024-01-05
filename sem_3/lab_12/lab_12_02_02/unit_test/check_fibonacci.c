#include "check_fibonacci.h"

#include "fibonacci.h"

// Запрашивается ноль чисел Фибоначчи
START_TEST(zero_fib_num) {
#define N 1
    int fibs[N];
    fill_fibonacci(fibs, 0);
#undef N
} END_TEST

// Запрашивается одно число Фибоначчи
START_TEST(one_fib_num) {
#define N 1
    int fibs[N];
    int etalon_fibs[N] = {0};
    fill_fibonacci(fibs, N);
    ck_assert_mem_eq(fibs, etalon_fibs, sizeof(*fibs) * N);
#undef N
} END_TEST

// Запрашивается два числа Фибоначчи
START_TEST(two_fib_num) {
#define N 2
    int fibs[N];
    int etalon_fibs[N] = {0, 1};
    fill_fibonacci(fibs, N);
    ck_assert_mem_eq(fibs, etalon_fibs, sizeof(*fibs) * N);
#undef N
} END_TEST

// Запрашивается несколько чисел Фибоначчи
START_TEST(fib_nums) {
#define N 10
    int fibs[N];
    int etalon_fibs[N] = {
        0, 1, 1, 2, 3,
        5, 8, 13, 21, 34
    };
    fill_fibonacci(fibs, N);
    ck_assert_mem_eq(fibs, etalon_fibs, sizeof(*fibs) * N);
#undef N
} END_TEST

Suite *fill_fibonacci_suite(void) {
    Suite *s;
    TCase *tests;

    s = suite_create("\nFILL_FIBONACCI");
    tests = tcase_create(" tests ");

    tcase_add_test(tests, fib_nums);
    tcase_add_test(tests, two_fib_num);
    tcase_add_test(tests, one_fib_num);
    tcase_add_test(tests, zero_fib_num);

    suite_add_tcase(s, tests);

    return s;
}
