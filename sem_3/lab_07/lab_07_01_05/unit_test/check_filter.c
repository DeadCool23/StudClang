#include "check_filter.h"

#include <stddef.h>

//========================================================
// sum testing
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

//===================================================
// key testing
//---------------------------------------------------

// Некорректный укзатель
START_TEST(test_key_first_arg_null) {
    size_t size = 3;
    int arr[3] = {3, 2, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(NULL, arr + size, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Фильтрация одного элемента
START_TEST(test_key_src_one_elem) {
    size_t size = 1;
    int arr[1] = {3};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Некорректный укзатель
START_TEST(test_key_second_arg_null) {
    int arr[3] = {3, 2, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, NULL, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Некорректные укзатели
START_TEST(test_key_pointers_order) {
    size_t size = 3;
    int arr[3] = {3, 2, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr + size, arr, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST

// Один элемент подходят по усовию
START_TEST(test_key_one_elem_in_arr) {
    size_t size = 5;
    int arr[5] = {100, 3, 2, 3, 20};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, OK);
    int *a = pb;
    int res[] = {100};
    size_t n = (size_t)(pe - pb);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);

    if (!rc) free(pb);
}
END_TEST

// Несколько элементов подходят по усовию
START_TEST(test_key_ok) {
    size_t size = 5;
    int arr[5] = {20, 5, 9, 3, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, OK);
    int *a = pb;
    int res[] = {20, 9, 3};
    size_t n = (size_t)(pe - pb);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], res[i]);

    if (!rc)
        free(pb);

}
END_TEST

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
