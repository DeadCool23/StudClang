#include "check_add_del.h"
#include "associative_array.h"

// Тестирование assoc_array_insert
//--------------------------------------------------------------

// Пустой ключ
START_TEST(empty_key_for_insert) {
    assoc_array_t arr = assoc_array_create();
    ck_assert_int_eq(assoc_array_insert(arr, "", 10), ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
} END_TEST

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_insert) {
    ck_assert_int_eq(assoc_array_insert(NULL, "key", 10), ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

// Вставка элемента
START_TEST(insert) {
    assoc_array_t arr = assoc_array_create();
    assoc_array_error_t err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    int *value, etalon_value = 10; 
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*value, etalon_value);
    assoc_array_destroy(&arr);
} END_TEST

Suite *assoc_array_insert_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___INSERT___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, empty_key_for_insert);
    tcase_add_test(tc_neg, uninitialize_arr_for_insert);
    tcase_add_test(tc_pos, insert);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

// Тестирование assoc_array_clear
//--------------------------------------------------------------

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_clear) {
    assoc_array_error_t err;
    err = assoc_array_clear(NULL);
    ck_assert_int_eq(err, ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

// Очистка массива с одним элементом
START_TEST(clear_arr_with_one_elem) {
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_clear(arr);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
} END_TEST

// Очистка массива с несколькими элементами
START_TEST(clear_arr_with_many_elem) {
#define N 2
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    char *keys[N] = { 
        "key",
        "key1",
    };
    int vals[N] = { 10, 10 };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    err = assoc_array_clear(arr);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    for (size_t i = 0; i < N; i++)
        ck_assert_int_eq(assoc_array_find(arr, keys[i], &value), ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
#undef N
} END_TEST

// Очистка пустого массива
START_TEST(clear_empty_arr) {
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_clear(arr);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
} END_TEST

Suite *assoc_array_clear_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___CLEAR___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, uninitialize_arr_for_clear);

    tcase_add_test(tc_pos, clear_arr_with_one_elem);
    tcase_add_test(tc_pos, clear_arr_with_many_elem);
    tcase_add_test(tc_pos, clear_empty_arr);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}

// Тестирование assoc_array_remove
//--------------------------------------------------------------

// Пустой ключ
START_TEST(empty_key_for_remove) {
    assoc_array_t arr = assoc_array_create();
    ck_assert_int_eq(assoc_array_remove(arr, ""), ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
} END_TEST

// Непроинициализированный массив
START_TEST(uninitialize_arr_for_remove) {
    ck_assert_int_eq(assoc_array_remove(NULL, "key"), ASSOC_ARRAY_INVALID_PARAM);
} END_TEST

START_TEST(remove_from_array_with_one_element) {
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    err = assoc_array_insert(arr, "key", 10);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_remove(arr, "key");
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
} END_TEST

START_TEST(remove_from_array_with_two_elements) {
#define N 2
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    char *keys[N] = { 
        "key",
        "key1",
    };
    int vals[N] = { 10, 10 };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    err = assoc_array_remove(arr, "key1");
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key1", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
#undef N
} END_TEST

START_TEST(remove_from_array_with_many_elements) {
#define N 3
    int *value;
    assoc_array_error_t err;
    assoc_array_t arr = assoc_array_create();
    char *keys[N] = { 
        "key",
        "key1",
        "key2",
    };
    int vals[N] = { 10, 10 };
    for (size_t i = 0; i < N; i++) {
        err = assoc_array_insert(arr, keys[i], vals[i]);
        ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    }
    err = assoc_array_remove(arr, "key1");
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key2", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_OK);
    err = assoc_array_find(arr, "key1", &value);
    ck_assert_int_eq(err, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
#undef N
} END_TEST

Suite *assoc_array_remove_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___REMOVE___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, empty_key_for_remove);
    tcase_add_test(tc_neg, uninitialize_arr_for_remove);
    tcase_add_test(tc_pos, remove_from_array_with_one_element);
    tcase_add_test(tc_pos, remove_from_array_with_two_elements);
    tcase_add_test(tc_pos, remove_from_array_with_many_elements);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
