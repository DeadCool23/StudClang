#include "check_insert.h"

#include "list.h"
#include "node.h"
#include "storage.h"
#include "check_process.h"

// Тестирование insert
//------------------------------------------------------------------------------------------------------------------

// Некорректный вставляемый элемент
START_TEST(null_in_el) {
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
    point_t bef = {3, 0};
    list_t *before = node_create(&bef);
    ck_assert_ptr_nonnull(before);
    
    insert(&head, NULL, before);

    point_t etalon_points[N] = {
        {3, 0},
        {2, 0},
        {1, 0},
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
    node_destroy(before);
    free_list(head);
#undef N
} END_TEST

// Некорректный искомый узел
START_TEST(null_search_node) {
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
    point_t elem = {4, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    
    insert(&head, element, NULL);

    point_t etalon_points[N] = {
        {3, 0},
        {2, 0},
        {1, 0},
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
    node_destroy(element);
    free_list(head);
#undef N
} END_TEST

// Некорректная голова
START_TEST(null_head) {
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
    list_t **ptr_head = &head;
    ptr_head = NULL;
    ck_assert_ptr_nonnull(head);
    point_t elem = {4, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    point_t bef = {3, 0};
    list_t *before = node_create(&bef);
    ck_assert_ptr_nonnull(before);
    
    insert(ptr_head, element, before);

    point_t etalon_points[N] = {
        {3, 0},
        {2, 0},
        {1, 0},
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
    node_destroy(element);
    node_destroy(before);
    free_list(head);
#undef N
} END_TEST

// Вставка в голову
START_TEST(insert_in_head) {
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
    point_t elem = {4, 0};
    list_t *element = node_create(&elem);
    ck_assert_ptr_nonnull(element);
    list_t *before = head;
    ck_assert_ptr_nonnull(before);
    
    insert(&head, element, before);

    point_t etalon_points[N + 1] = {
        {4, 0},
        {3, 0},
        {2, 0},
        {1, 0},
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
        {2, 0},
        {1, 0},
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
    list_t *before = head->next->next;
    
    insert(&head, element, before);

    point_t etalon_points[N + 1] = {
        {2, 0},
        {1, 0},
        {4, 0},
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
START_TEST(not_insert) {
#define N 3
    point_t points[N] = {
        {2, 0},
        {1, 0},
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
    point_t bef = {4, 0};
    list_t *before = node_create(&bef);
    ck_assert_ptr_nonnull(before);
    
    insert(&head, element, before);

    point_t etalon_points[N] = {
        {2, 0},
        {1, 0},
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
    node_destroy(element);
    node_destroy(before);
    free_list(head);
#undef N
} END_TEST

Suite *insert_suite(void) {
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("\n___INSERT___");

    tc_pos = tcase_create(" positives ");
    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, null_head);
    tcase_add_test(tc_neg, null_in_el);
    tcase_add_test(tc_neg, null_search_node);
    tcase_add_test(tc_pos, insert_in_head);
    tcase_add_test(tc_pos, insert_in_mid);
    tcase_add_test(tc_pos, not_insert);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
