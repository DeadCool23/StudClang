#include "check_subj.h"
#include <check.h>

#define EPS 1e-10

#include <math.h>
#include <string.h>

int ck_assert_subj_eq(const subject_t *X, const subject_t *Y) {
    int diff = 0;
    diff = (fabs(X->volume - Y->volume) < EPS) && !diff ? 0 : 1;
    diff = (fabs(X->weight - Y->weight) < EPS) && !diff ? 0 : 1;
    diff = !strcmp(X->name, Y->name) &&!diff ? 0 : 1;
    return diff;
}

// Тестирование subj_density_calc
//-------------------------------------------------------------------------------

// Плотность равная единице
START_TEST(unit_density_test) {
    subject_t test_subj = {.volume = 1, .weight = 1, .name = " "};
    double dens = subject_density_calc(&test_subj);

    double etalon_dens = 1.0;
    ck_assert_double_eq_tol(dens, etalon_dens, EPS);
} END_TEST

// Дробная плотность
START_TEST(std_density_test) {
    subject_t test_subj = {.volume = 4, .weight = 1, .name = " "};
    double dens = subject_density_calc(&test_subj);

    double etalon_dens = 0.25;
    ck_assert_double_eq_tol(dens, etalon_dens, EPS);
} END_TEST

Suite* subj_density_calc_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBJ_DENSITY_CALC___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, unit_density_test);
    tcase_add_test(tc_pos, std_density_test);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование subj_init
//----------------------------------------------------------------------

START_TEST(subj_init_test) {
    double volume = 1;
    double weight = 1;
    char *name = "Name";
    subject_t subj = {.name = NULL};
    err_t err = subj_init(&subj, name, weight, volume);

    ck_assert_int_eq(err, OK);
    ck_assert_str_eq(subj.name, name);
    ck_assert_double_eq(subj.volume, volume);
    ck_assert_double_eq(subj.weight, weight);
    free_subj(&subj);
} END_TEST

Suite* subj_init_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBJ_INIT___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, subj_init_test);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование subj_cpy
//----------------------------------------------------------------------

START_TEST(subj_cpy_test) {
    subject_t dst_subj = {.name = NULL};
    subject_t src_subj = {.volume = 1, .weight = 1, .name = "ABC"};
    subj_cpy(&dst_subj, &src_subj);

    subject_t etalon_subj = { .volume = 1, .weight = 1, .name = "ABC"};
    ck_assert_int_eq(ck_assert_subj_eq(&dst_subj, &etalon_subj), 0);
    free_subj(&dst_subj);
} END_TEST

Suite* subj_cpy_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBJ_CPY___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, subj_cpy_test);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование subj_cmp
//----------------------------------------------------------------------

// Левый объект больше
START_TEST(left_subj_g) {
    subject_t lsubj = {.volume = 1, .weight = 1};
    subject_t rsubj = {.volume = 4, .weight = 1};
    int cmp = subjs_cmp(&lsubj, &rsubj);

    int etalon_cmp = 1;
    ck_assert_int_eq(cmp, etalon_cmp);
} END_TEST

// Правый объект больше
START_TEST(right_subj_g) {
    subject_t lsubj = {.volume = 10, .weight = 1};
    subject_t rsubj = {.volume = 1, .weight = 1};
    int cmp = subjs_cmp(&lsubj, &rsubj);

    int etalon_cmp = -1;
    ck_assert_int_eq(cmp, etalon_cmp);
} END_TEST

// Объекты равны
START_TEST(subjs_equal) {
    subject_t lsubj = {.volume = 1, .weight = 1};
    subject_t rsubj = {.volume = 1, .weight = 1};
    int cmp = subjs_cmp(&lsubj, &rsubj);

    int etalon_cmp = 0;
    ck_assert_int_eq(cmp, etalon_cmp);
} END_TEST

Suite* subjs_cmp_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBJS_CMP___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, left_subj_g);
    tcase_add_test(tc_pos, right_subj_g);
    tcase_add_test(tc_pos, subjs_equal);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование substr_search_in_name
//----------------------------------------------------------------------

// Нед подстроки в имени
START_TEST(no_sbstr_in_name) {
    subject_t subj = {.name = "abcdef"};
    bool is_in = substr_search_in_name(&subj, "ghij");

    bool etalon_is_in = false;
    ck_assert_int_eq(is_in, etalon_is_in);
} END_TEST

// Подстрока не в начале имени
START_TEST(sbstr_not_in_beg_of_name) {
    subject_t subj = {.name = "abcdef"};
    bool is_in = substr_search_in_name(&subj, "cd");

    bool etalon_is_in = false;
    ck_assert_int_eq(is_in, etalon_is_in);
} END_TEST

// Подстрока не полностью в начале имени
START_TEST(sbstr_not_full_in_beg_of_name) {
    subject_t subj = {.name = "abcdef"};
    bool is_in = substr_search_in_name(&subj, "abcjl");

    bool etalon_is_in = false;
    ck_assert_int_eq(is_in, etalon_is_in);
} END_TEST

// Подстрока в начале имени
START_TEST(sbstr_in_bef_of_name) {
    subject_t subj = {.name = "abcdef"};
    bool is_in = substr_search_in_name(&subj, "abc");

    bool etalon_is_in = true;
    ck_assert_int_eq(is_in, etalon_is_in);
} END_TEST

Suite* substr_search_in_name_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUBSTR_SEARCH_IN_NAME___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, no_sbstr_in_name);
    tcase_add_test(tc_pos, sbstr_in_bef_of_name);
    tcase_add_test(tc_pos, sbstr_not_in_beg_of_name);
    tcase_add_test(tc_pos, sbstr_not_full_in_beg_of_name);

    suite_add_tcase(s, tc_pos);

    return s;
}
