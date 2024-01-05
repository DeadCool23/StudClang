#include "check_find.h"

#include "list.h"
#include "storage.h"
#include "check_process.h"

// Тестирование find
//------------------------------------------------------------------------------------------------------------------

START_TEST(finded) {
#define N 3
    point_t points[] = {
        {0, 2},
        {2, 2},
        {7, 9},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    double dist = 2.0;
    list_t *finded_data = find(head, &dist,dist_cmp);

    ck_assert_ptr_nonnull(finded_data);
    point_t etalon_point = {0, 2};
    ck_assert_int_eq(ck_assert_point_eq(finded_data->element, &etalon_point), 0);
    free_list(head);
#undef N
} END_TEST

START_TEST(not_finded) {
#define N 3
    point_t points[] = {
        {0, 2},
        {2, 2},
        {7, 9},
    };
    points_t storage = {
        .points = points,
        .cnt = N,
        .capacity = N,
    };
    list_t *head = storage2list(&storage);
    ck_assert_ptr_nonnull(head);
    double dist = 9999.0;
    list_t *finded_data = find(head, &dist,dist_cmp);

    ck_assert_ptr_null(finded_data);
    free_list(head);
#undef N
} END_TEST

Suite *find_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___FIND___");

    tc_pos = tcase_create(" positives ");
    tcase_add_test(tc_pos, finded);
    tcase_add_test(tc_pos, not_finded);

    suite_add_tcase(s, tc_pos);

    return s;
}
