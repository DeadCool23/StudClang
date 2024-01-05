#include "check_min_max.h"
#include "associative_array.h"

// Тестирование assoc_array_min
//--------------------------------------------------------------

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_min) {
    assoc_array_error_t err;
    err = assoc_array_min(NULL, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

// Пустой массив
START_TEST(min_in_empty_arr) {
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_min(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
} END_TEST

// Массив с одним элементом
START_TEST(min_in_arr_with_one_element) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    int *value, etalon_value = 10;
    err = assoc_array_min(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
} END_TEST

// Массив с несколькими элементами
START_TEST(min_in_arr_with_many_elements) {
#define N 2
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    int vals[N] = { 10, 2 };
    char *keys[N] = { "a", "b" };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    int *value, etalon_value = 10;
    err = assoc_array_min(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
#undef N
} END_TEST


Suite *assoc_array_min_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___MIN___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, uninitialize_arr_for_min);

    tcase_add_test(tc_pos, min_in_empty_arr);
    tcase_add_test(tc_pos, min_in_arr_with_one_element);
    tcase_add_test(tc_pos, min_in_arr_with_many_elements);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

// Тестирование assoc_array_max
//--------------------------------------------------------------

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_max) {
    assoc_array_error_t err;
    err = assoc_array_max(NULL, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

// Пустой массив
START_TEST(max_in_empty_arr) {
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_max(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
} END_TEST

// Массив с одним элементом
START_TEST(max_in_arr_with_one_element) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    int *value, etalon_value = 10;
    err = assoc_array_max(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
} END_TEST

// Массив с несколькими элементами
START_TEST(max_in_arr_with_many_elements) {
#define N 2
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    int vals[N] = { 10, 2 };
    char *keys[N] = { "a", "b" };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    int *value, etalon_value = 2;
    err = assoc_array_max(arr, &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
#undef N
} END_TEST


Suite *assoc_array_max_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___MAX___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, uninitialize_arr_for_max);

    tcase_add_test(tc_pos, max_in_empty_arr);
    tcase_add_test(tc_pos, max_in_arr_with_one_element);
    tcase_add_test(tc_pos, max_in_arr_with_many_elements);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
