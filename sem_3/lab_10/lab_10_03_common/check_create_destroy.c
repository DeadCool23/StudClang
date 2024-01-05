#include "check_create_destroy.h"
#include "associative_array.h"

// Тестирование assoc_array_create
//--------------------------------------------------------------

START_TEST(created) {
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_nonnull(arr);
    assoc_array_destroy(&arr);
} END_TEST

Suite *assoc_array_create_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___CREATE___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, created);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование assoc_array_destoy
//--------------------------------------------------------------

START_TEST(destroied) {
    assoc_array_t arr = assoc_array_create();
    assoc_array_destroy(&arr);
    ck_assert_ptr_null(arr);
} END_TEST

Suite *assoc_array_destoy_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___DESTROY___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, destroied);

    suite_add_tcase(s, tc_pos);

    return s;
}