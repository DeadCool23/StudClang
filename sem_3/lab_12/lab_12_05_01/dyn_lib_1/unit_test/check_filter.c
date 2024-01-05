#include "check_filter.h"

#include <stddef.h>
#include "filter.h"

// Тестирование sum
//--------------------------------------------------------

// Сумма элементов массива из нескольких чисел
START_TEST(test_sum_of_lot_els_arr)
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    int expected_sum = 15;
    int result = sum(arr, arr + size);
    ck_assert_int_eq(result, expected_sum);
}
END_TEST

// Сумма элементов массива состоящего из одного элемента
START_TEST(test_sum_one_el_arr)
{
    int arr[] = {1};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    int expected_sum = 1;
    int result = sum(arr, arr + size);
    ck_assert_int_eq(result, expected_sum);
}
END_TEST


Suite* sum_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUM___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_sum_of_lot_els_arr);
    tcase_add_test(tc_pos, test_sum_one_el_arr);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование key
//---------------------------------------------------

// Некорректный укзатель
START_TEST(test_key_first_arg_null) {
    size_t size = 3;
    int arr[3] = {3, 2, 1};
    int *pb = NULL;
    size_t len = 3;

    int rc = key(NULL, arr + size, pb, len);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Фильтрация одного элемента
START_TEST(test_key_src_one_elem) {
    size_t size = 1;
    int arr[1] = {3};
    int *pb = NULL;
    size_t len = 2;

    int rc = key(arr, arr + size, pb, len);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Некорректный укзатель
START_TEST(test_key_second_arg_null) {
    int arr[3] = {3, 2, 1};
    int *pb = NULL;
    size_t len = 4;

    int rc = key(arr, NULL, pb, len);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Некорректные укзатели
START_TEST(test_key_pointers_order) {
    size_t size = 3;
    int arr[3] = {3, 2, 1};
    int *pb = NULL;
    size_t len = 5;

    int rc = key(arr + size, arr, pb, len);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Один элемент подходят по усовию
START_TEST(test_key_one_elem_in_arr) {
#define FILT_N 1
    size_t size = 5;
    int arr[5] = {100, 3, 2, 3, 20};
    int pb[FILT_N];
    size_t len = FILT_N;

    int rc = key(arr, arr + size, pb, len);

    ck_assert_int_eq(rc, OK);
    int *a = pb;
    int res[FILT_N] = {100};
    size_t n = len;
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
#undef FILT_N
} END_TEST

// Несколько элементов подходят по усовию
START_TEST(test_key_ok) {
#define FILT_N 3
    size_t size = 5;
    int arr[5] = {20, 5, 9, 3, 1};
    int pb[FILT_N];
    size_t len = FILT_N;

    int rc = key(arr, arr + size, pb, len);

    ck_assert_int_eq(rc, OK);
    int *a = pb;
    int res[FILT_N] = {20, 9, 3};
    size_t n = len;
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);
#undef FILT_N
} END_TEST

Suite* key_suite(void) {
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n___KEY___");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, test_key_first_arg_null);
    tcase_add_test(tc_neg, test_key_second_arg_null);
    tcase_add_test(tc_neg, test_key_pointers_order);
    tcase_add_test(tc_neg, test_key_src_one_elem);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_key_one_elem_in_arr);
    tcase_add_test(tc_pos, test_key_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}
