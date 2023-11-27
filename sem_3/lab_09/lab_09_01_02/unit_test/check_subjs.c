#include "check_subjs.h"

#include "subj_arr.h"
#include "check_subj.h"
#include <check.h>

int ck_assert_subjs_arr_eq(const subject_t *X, const subject_t *Y, size_t n) {
    int diff = 0;
    for (size_t i = 0; i < n && !diff; i++)
        diff = ck_assert_subj_eq(X + i, Y + i);
    return diff;
}

// Тестирование subjects_sort_by_density
//--------------------------------------------------------------

// Пустой массив
START_TEST(test_subjects_sort_by_density_empty_array) {
    subject_t a[1] = {{.name = NULL}};
    subject_t res[1]= {{.name = NULL}};
    size_t n = 0;
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Массив из одного числа
START_TEST(test_subjects_sort_by_density_single_element) {
    subject_t a[] = {{.name = "abc", .volume = 1, .weight = 1}};
    subject_t res[] = {{.name = "abc", .volume = 1, .weight = 1}};
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Убывающий массив из двух элеме
START_TEST(test_subjects_sort_by_density_two_els_reverse_sorted_array) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 4}, 
        {.name = "a", .volume = 1, .weight = 1}
    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 4}
    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Возрастающий массив из двух элементов
START_TEST(test_subjects_sort_by_density_two_els_sorted_array) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 4}
    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 4}
    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Возрастающий массив
START_TEST(test_subjects_sort_by_density_sorted_array) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 4},
        {.name = "a", .volume = 1, .weight = 5}

    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 4},
        {.name = "a", .volume = 1, .weight = 5}

    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Убывающий массив
START_TEST(test_subjects_sort_by_density_reverse_sorted_array) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 5}, 
        {.name = "a", .volume = 1, .weight = 4},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 1}

    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 4},
        {.name = "a", .volume = 1, .weight = 5}
    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Случайный массив без повторений
START_TEST(test_subjects_sort_by_density_random_array) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 4}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 5},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 1}

    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 4},
        {.name = "a", .volume = 1, .weight = 5}
    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

// Случайный массив с повторениями
START_TEST(test_subjects_sort_by_density_random_array_with_repeat) {
    subject_t a[] = {
        {.name = "a", .volume = 1, .weight = 4}, 
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 1},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 1}

    };
    subject_t res[] = {
        {.name = "a", .volume = 1, .weight = 1}, 
        {.name = "a", .volume = 1, .weight = 1},
        {.name = "a", .volume = 1, .weight = 2},
        {.name = "a", .volume = 1, .weight = 3},
        {.name = "a", .volume = 1, .weight = 4}
    };
    size_t n = sizeof(a) / sizeof(*a);
    subjects_sort_by_density(a, n, subjs_cmp);
    ck_assert_int_eq(ck_assert_subjs_arr_eq(a, res, n), 0);
} END_TEST

Suite* subjects_sort_by_density_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBSTR_SEARCH_IN_NAME___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_subjects_sort_by_density_empty_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_single_element);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_two_els_reverse_sorted_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_two_els_sorted_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_sorted_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_reverse_sorted_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_random_array);
    tcase_add_test(tc_pos, test_subjects_sort_by_density_random_array_with_repeat);


    suite_add_tcase(s, tc_pos);

    return s;
}
