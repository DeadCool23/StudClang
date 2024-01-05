#include "check_cmp.h"

#include "point.h"
#include <stdbool.h>

// Тестирование dist_cmp
//----------------------------------------------------------------------------------

// Точка не на заданном растоянии
START_TEST(ne_dist) {
    double dist = 2.0;
    point_t point = {1, 1};
    int res = dist_cmp(&point, &dist);
    ck_assert_int_eq(res, 1);
} END_TEST

// Точка на заданном растоянии
START_TEST(eq_dist) {
    double dist = 2.0;
    point_t point = {0, 2};
    int res = dist_cmp(&point, &dist);
    ck_assert_int_eq(res, 0);
} END_TEST

Suite *dist_cmp_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___DIST_CMP___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, ne_dist);
    tcase_add_test(tc_pos, eq_dist);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование points_cmp
//----------------------------------------------------------------------------------

// Первая точка дальше от начала координат
START_TEST(first_lt) {
    point_t point1 = {2, 2};
    point_t point2 = {0, 2};
    int res = points_cmp(&point1, &point2);
    ck_assert_int_gt(res, 0);
} END_TEST

// Вторая точка дальше от начала координат
START_TEST(first_gt) {
    point_t point1 = {0, 2};
    point_t point2 = {2, 2};
    int res = points_cmp(&point1, &point2);
    ck_assert_int_lt(res, 0);
} END_TEST

// Точкаи равноудалены
START_TEST(points_eq) {
    point_t point1 = {0, 2};
    point_t point2 = {0, 2};
    int res = points_cmp(&point1, &point2);
    ck_assert_int_eq(res, 0);
} END_TEST

Suite *points_cmp_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___POINTS_CMP___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, first_lt);
    tcase_add_test(tc_pos, first_gt);
    tcase_add_test(tc_pos, points_eq);

    suite_add_tcase(s, tc_pos);

    return s; 
}
