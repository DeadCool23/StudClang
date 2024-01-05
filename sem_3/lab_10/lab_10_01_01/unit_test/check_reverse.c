#include "check_reverse.h"

#include "list.h"
#include "storage.h"
#include "check_process.h"

// Тестирование reverse
//--------------------------------------------------------------

// Список из одного элемента
START_TEST(empty_list) {
#define N 0
    point_t points[N + 1];
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_null(head);
    head = sort(head, points_cmp);

    point_t etalon_points[N + 1];
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N,
        .capacity = N,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_null(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N
} END_TEST

// Список из одного элемента
START_TEST(one_el_list) {
#define N 1
    point_t points[] = {
        {1, 2},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    head = sort(head, points_cmp);

    point_t etalon_points[] = {
        {1, 2},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N,
        .capacity = N,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N 
} END_TEST


// Список из двух элементов
START_TEST(two_els_list) {
#define N 2
    point_t points[N] = {
        {2, 0},
        {1, 0},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    head = sort(head, points_cmp);

    point_t etalon_points[N] = {
        {1, 0},
        {2, 0},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N,
        .capacity = N,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N 
} END_TEST

// Список из нескольких элемента
START_TEST(big_list) {
#define N 3
    point_t points[N] = {
        {3, 0},
        {2, 0},
        {1, 0},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    head = sort(head, points_cmp);

    point_t etalon_points[N] = {
        {1, 0},
        {2, 0},
        {3, 0},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N,
        .capacity = N,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N 
} END_TEST

Suite *reverse_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___REVERSE___");

    tc_pos = tcase_create(" positives ");
    tcase_add_test(tc_pos, empty_list);
    tcase_add_test(tc_pos, one_el_list);
    tcase_add_test(tc_pos, two_els_list);
    tcase_add_test(tc_pos, big_list);

    suite_add_tcase(s, tc_pos);

    return s;
}
