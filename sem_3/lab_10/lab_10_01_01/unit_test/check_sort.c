#include "check_sort.h"

#include "list.h"
#include "point.h"
#include "storage.h"
#include "check_process.h"
#include <check.h>

// Тестирование sort
//------------------------------------------------------------------------------------------------------------------

// Сортировка одного элемента
START_TEST (one_el_list) {
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

// Сортировка пустого списка
START_TEST (empty_list) {
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

// Сортировка списка из двух отсортированных точек 
START_TEST (two_els_sorted_list) {
#define N 2
    point_t points[N] = {
        {1, 1},
        {2, 2},
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
        {1, 1},
        {2, 2},
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

// Сортировка списка из двух обратно-отсортированных точек 
START_TEST (two_els_rev_sorted_list) {
#define N 2
    point_t points[N] = {
        {2, 2},
        {1, 1},
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
        {1, 1},
        {2, 2},
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

// Сортировка осортированного списка
START_TEST (sorted_list) {
#define N 5
    point_t points[N] = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5}
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
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5}
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

// Сортировка обратно-осортированного списка
START_TEST (rev_sorted_list) {
#define N 5
    point_t points[N] = {
        {5, 5},
        {4, 4},
        {3, 3},
        {2, 2},
        {1, 1},
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
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5}
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

// Сортировка рандомного спика без повторений
START_TEST (rand_list_without_repeats) {
#define N 5
    point_t points[N] = {
        {2, 2},
        {4, 4},
        {3, 0},
        {5, 5},
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
        {2, 2},
        {3, 0},
        {4, 4},
        {5, 5}
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

// Сортировка рандомного спика с повторениями
START_TEST (rand_list_with_repeats) {
#define N 5
    point_t points[N] = {
        {4, 3},
        {1, 2},
        {3, 0},
        {4, 4},
        {2, 1},
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
        {1, 2},
        {2, 1},
        {3, 0},
        {4, 3},
        {4, 4}
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

Suite *sort_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SORT___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, one_el_list);
    tcase_add_test(tc_pos, empty_list);
    tcase_add_test(tc_pos, two_els_sorted_list);
    tcase_add_test(tc_pos, two_els_rev_sorted_list);
    tcase_add_test(tc_pos, sorted_list);
    tcase_add_test(tc_pos, rev_sorted_list);
    tcase_add_test(tc_pos, rand_list_without_repeats);
    tcase_add_test(tc_pos, rand_list_with_repeats);

    suite_add_tcase(s, tc_pos);

    return s; 
}

// Тестирование sorted_insert
//------------------------------------------------------------------------------------------------------------------

// Вставка в голову
START_TEST(insert_in_head) {
#define N 3
    point_t points[N] = {
        {1, 0},
        {2, 0},
        {3, 0},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    point_t elem = {0, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    
    sorted_insert(&head, element, points_cmp);

    point_t etalon_points[N + 1] = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N + 1,
        .capacity = N + 1,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N
} END_TEST

// Втавка в середину
START_TEST(insert_in_mid) {
#define N 3
    point_t points[N] = {
        {1, 0},
        {2, 0},
        {3, 0},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    point_t elem = {1, 1};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    
    sorted_insert(&head, element, points_cmp);

    point_t etalon_points[N + 1] = {
        {1, 0},
        {1, 1},
        {2, 0},
        {3, 0},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N + 1,
        .capacity = N + 1,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N
} END_TEST

// Не нашлось место вставки
START_TEST(insert_in_tail) {
#define N 3
    point_t points[N] = {
        {1, 0},
        {2, 0},
        {3, 0},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    point_t elem = {4, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    
    sorted_insert(&head, element, points_cmp);

    point_t etalon_points[N + 1] = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
    };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N + 1,
        .capacity = N + 1,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N
} END_TEST

// Не нашлось место вставки
START_TEST(insert_in_empty) {
#define N 0
    list_t *head = NULL;
    point_t elem = {4, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    
    sorted_insert(&head, element, points_cmp);

    point_t etalon_points[N + 1] = { {4, 0} };
    points_t etalon_storage = {
        .points = etalon_points,
        .cnt = N + 1,
        .capacity = N + 1,
    };
    list_t *etalon_head = storage2list(&etalon_storage);
    ck_assert_ptr_nonnull(etalon_head);
    ck_assert_int_eq(ck_assert_list_eq(head, etalon_head), 0);
    free_list(etalon_head);
    free_list(head);
#undef N
} END_TEST

Suite *sorted_insert_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SORTED_INSERT___");

    tc_pos = tcase_create(" positives ");
    
    tcase_add_test(tc_pos, insert_in_head);
    tcase_add_test(tc_pos, insert_in_mid);
    tcase_add_test(tc_pos, insert_in_tail);
    tcase_add_test(tc_pos, insert_in_empty);

    suite_add_tcase(s, tc_pos);

    return s;
}
