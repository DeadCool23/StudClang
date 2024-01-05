#include "check_find_each.h"
#include "associative_array.h"
#include <check.h>

// Тестирование assoc_array_find
//--------------------------------------------------------------

// Пустой ключ
START_TEST(empty_key_for_find) {
    assoc_array_t arr = assoc_array_create();
    ck_assert_int_eq(assoc_array_find(arr, "", NULL), ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
} END_TEST

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_find) {
    ck_assert_int_eq(assoc_array_find(NULL, "key", NULL), ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

START_TEST(finded) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    int *value, etalon_value = 10; 
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
} END_TEST

START_TEST(not_finded) {
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
} END_TEST

Suite *assoc_array_find_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___FIND___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, empty_key_for_find);
    tcase_add_test(tc_neg, uninitialize_arr_for_find);
    tcase_add_test(tc_pos, finded);
    tcase_add_test(tc_pos, not_finded);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

// Тестирование assoc_array_each
//--------------------------------------------------------------

/// @brief Функция заглушка 
static void plugfn(const char *key, int *value, void *param) { 
    (void)key;
    (void)value;
    (void)param;
}
/// @brief  Функция возведения числа в квадрат
static void square(const char *key, int *value, void *param) {
    (void)key;
    (void)param;
    *value *= *value;
}

/// @brief Функция суммирования элемента с параметром
static void summator(const char *key, int *value, void *param) { 
    (void)key;
    *value += *(int *)param;
}

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_each) {
    assoc_array_error_t err;
    err = assoc_array_each(NULL, plugfn, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

START_TEST(not_func_given) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_each(arr, NULL, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
} END_TEST

// Пустой массив
START_TEST(each_empty_arr) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_each(arr, plugfn, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
} END_TEST

// Вызываемая функция работает с данными массива
START_TEST(each_working_with_data) {
#define N 2
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    int vals[N] = { 10, 2 };
    char *keys[N] = { "key", "key1" };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    err = assoc_array_each(arr, square, NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    
    int *value; 
    int etalon_vals[N] = { 100, 4 };
    for (size_t i = 0; i < N; i++) {
        ck_assert_int_eq(assoc_array_find(arr, keys[i], &value), ASSOC_ARRAY_OK);
        ck_assert_int_eq(etalon_vals[i], *value);
    }
    assoc_array_destroy(&arr);
#undef N
} END_TEST

// Вызываемая функция работает с доп параметрами
START_TEST(each_working_with_param) {
#define N 2
    int added_num = 2;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    int vals[N] = { 10, 2 };
    char *keys[N] = { "key", "key1" };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    err = assoc_array_each(arr, summator, &added_num);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    
    int *value; 
    int etalon_vals[N] = { 12, 4 };
    for (size_t i = 0; i < N; i++) {
        ck_assert_int_eq(assoc_array_find(arr, keys[i], &value), ASSOC_ARRAY_OK);
        ck_assert_int_eq(etalon_vals[i], *value);
    }
    assoc_array_destroy(&arr);
} END_TEST

Suite *assoc_array_each_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___EACH___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, uninitialize_arr_for_each);
    tcase_add_test(tc_neg, not_func_given);

    tcase_add_test(tc_pos, each_working_with_data);
    tcase_add_test(tc_pos, each_working_with_param);
    tcase_add_test(tc_pos, each_empty_arr);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
