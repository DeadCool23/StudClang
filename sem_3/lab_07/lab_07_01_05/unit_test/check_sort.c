#include "check_sort.h"

#include <stddef.h>

//============================================================
// int_compare testing
//------------------------------------------------------------

// Правое число больше
START_TEST(test_int_compare_positive) {
int left = 6;
int right = 9;
    int exp_res = -3;
    int res = int_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Числа равны
START_TEST(test_int_compare_zero) {
    int left = 6;
    int right = 6;
    int exp_res = 0;
    int res = int_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Левое число больше
START_TEST(test_int_compare_negative) {
    int left = 9;
    int right = 6;
    int exp_res = 3;
    int res = int_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

Suite *int_compare_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___INT COMPARE___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_int_compare_positive);
    tcase_add_test(tc_pos, test_int_compare_zero);
    tcase_add_test(tc_pos, test_int_compare_negative);

    suite_add_tcase(s, tc_pos);

    return s;
}

//==============================================================
//char_compare testing
//--------------------------------------------------------------

int char_compare(const void *left, const void *right)
{
    return *(char *)left - *(char *)right;
}

// Правый символ больше
START_TEST(test_char_compare_positive) {
    char left = '6';
    char right = '9';
    int exp_res = -3;
    int res = char_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Символы равны
START_TEST(test_char_compare_zero) {
    char left = '6';
    char right = '6';
    int exp_res = 0;
    int res = char_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Левый символ больше
START_TEST(test_char_compare_negative) {
    char left = '9';
    char right = '6';
    int exp_res = 3;
    int res = char_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

Suite *char_compare_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___CHAR COMPARE___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_char_compare_positive);
    tcase_add_test(tc_pos, test_char_compare_zero);
    tcase_add_test(tc_pos, test_char_compare_negative);

    suite_add_tcase(s, tc_pos);

    return s;
}

//==============================================================
//double_compare testing
//--------------------------------------------------------------

int double_compare(const void *left, const void *right)
{
#define EPS 1e-16
    return *(double *)left > *(double *)right ? 1 : fabs(*(double *)left - *(double *)right) < EPS ? 0 : -1;
}

// Правое число больше
START_TEST(test_double_compare_positive) {
    double left = 6;
    double right = 9;
    int exp_res = -1;
    int res = double_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Числа равны
START_TEST(test_double_compare_zero) {
    double left = 6;
    double right = 6;
    int exp_res = 0;
    int res = double_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

// Левое число больше
START_TEST(test_double_compare_negative) {
    double left = 9;
    double right = 6;
    int exp_res = 1;
    int res = double_compare(&left, &right);
    ck_assert_int_eq(res, exp_res);
} END_TEST

Suite *double_compare_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___DOUBLE COMPARE___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_double_compare_positive);
    tcase_add_test(tc_pos, test_double_compare_zero);
    tcase_add_test(tc_pos, test_double_compare_negative);

    suite_add_tcase(s, tc_pos);

    return s;
}

//==============================================================
// mysort testing
//--------------------------------------------------------------

// Пустой массив
START_TEST(test_mysort_empty_array) {
    int a[1];
    int res[1];
    size_t n = 0;
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Массив из одного числа
START_TEST(test_mysort_single_element) {
    int a[] = {1};
    int res[] = {1};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Убывающий массив из двух элеме
START_TEST(test_mysort_two_els_reverse_sorted_array) {
    int a[] = {2, 1};
    int res[] = {1, 2};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Возрастающий массив из двух элементов
START_TEST(test_mysort_two_els_sorted_array) {
    int a[] = {1, 2};
    int res[] = {1, 2};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Возрастающий массив
START_TEST(test_mysort_sorted_array) {
    int a[] = {1, 2, 3, 4, 5};
    int res[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Убывающий массив
START_TEST(test_mysort_reverse_sorted_array) {
    int a[] = {5, 4, 3, 2, 1};
    int res[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Случайный массив без повторений
START_TEST(test_mysort_random_array) {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int res[] = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Случайный массив с повторениями
START_TEST(test_mysort_random_array_with_repeat) {
    int a[] = {1, 4, 3, 3, 7, 8, 4, 9};
    int res[] = {1, 3, 3, 4, 4, 7, 8, 9};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), int_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Случайный массив символов
START_TEST(test_mysort_random_char_array) {
    char a[] = {1, 4, 3, 3, 7, 8, 4, 9};
    char res[] = {1, 3, 3, 4, 4, 7, 8, 9};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), char_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
} END_TEST

// Случайный массив чисел с плавающей точкой
START_TEST(test_mysort_random_double_array) {
    double a[] = {1, 4, 3, 3, 7, 8, 4, 9};
    double res[] = {1, 3, 3, 4, 4, 7, 8, 9};
    size_t n = sizeof(a) / sizeof(*a);
    mysort(a, n, sizeof(a[0]), double_compare);
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq(a[i], res[i]);
} END_TEST

Suite *mysort_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___MYSORT___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_mysort_empty_array);
    tcase_add_test(tc_pos, test_mysort_single_element);
    tcase_add_test(tc_pos, test_mysort_two_els_reverse_sorted_array);
    tcase_add_test(tc_pos, test_mysort_two_els_sorted_array);
    tcase_add_test(tc_pos, test_mysort_sorted_array);
    tcase_add_test(tc_pos, test_mysort_reverse_sorted_array);
    tcase_add_test(tc_pos, test_mysort_random_array);
    tcase_add_test(tc_pos, test_mysort_random_array_with_repeat);
    tcase_add_test(tc_pos, test_mysort_random_char_array);
    tcase_add_test(tc_pos, test_mysort_random_double_array);

    suite_add_tcase(s, tc_pos);

    return s;
}
