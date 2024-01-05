#include "check_polinom.h"
#include "check_process.h"
#include "nomen.h"
#include "polinom.h"
#include <check.h>

static polinom_t *arr2list(size_t n, nomen_t *nomens) {
    polinom_t *head = NULL;
    polinom_t *prev = head;
    for (size_t i = 0; i < n; i++) {
        if (!prev)
            head = nomen_create(nomens + i);
        else
            prev->next = nomen_create(nomens + i);
        ck_assert_ptr_nonnull(!prev ? head : prev->next);
        prev = !prev ? head : prev->next;
    }
    return head;
}

// Тестирование val
//----------------------------------------------------------

// Нулевой аргумент
START_TEST(zero_arg) {
#define N 2
    int arg = 0;
    nomen_t nomens[N] = {
        {2, 2},
        {2, 1}
    };
    polinom_t *head = arr2list(N, nomens);
    int res = val(head, arg);
    int etalon_res = 0;
    ck_assert_int_eq(res, etalon_res);
    free_polinom(head);
#undef N
} END_TEST

// Пустой список
START_TEST(empty_polinom) {
    int arg = 10;
    int res = val(NULL, arg);
    int etalon_res = 0;
    ck_assert_int_eq(res, etalon_res);
} END_TEST

// Отрицательное число
START_TEST(neg_arg) {
#define N 3
    int arg = -1;
    nomen_t nomens[N] = {
        {2, 2},
        {1, 1},
        {1, 0}
    };
    polinom_t *head = arr2list(N, nomens);
    int res = val(head, arg);
    int etalon_res = 2;
    ck_assert_int_eq(res, etalon_res);
    free_polinom(head);
#undef N
} END_TEST

// Стандартный полином
START_TEST(std_arg) {
#define N 2
    int arg = 7;
    nomen_t nomens[N] = {
        {4, 2},
        {1, 0},
    };
    polinom_t *head = arr2list(N, nomens);
    int res = val(head, arg);
    int etalon_res = 197;
    ck_assert_int_eq(res, etalon_res);
    free_polinom(head);
#undef N
} END_TEST

Suite *val_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___VAL___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, zero_arg);
    tcase_add_test(tc_pos, std_arg);
    tcase_add_test(tc_pos, neg_arg);
    tcase_add_test(tc_pos, empty_polinom);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование ddx
//----------------------------------------------------------

// Стандартный полином
START_TEST(std_polinom) {
#define N 3
    nomen_t nomens[N] = {
        {2, 2},
        {1, 1},
        {1, 0}
    };
    polinom_t *head = arr2list(N, nomens);
    head = ddx(head);

    nomen_t etalon_nomens[N - 1] = {
        {4, 1},
        {1, 0}
    };
    polinom_t *etalon_head = arr2list(N - 1, etalon_nomens);
    ck_assert_int_eq(ck_assert_polinom_eq(head, etalon_head), 0);
    free_polinom(etalon_head);
    free_polinom(head);
#undef N
} END_TEST

// Полином без свободного члена
START_TEST(polinom_without_free_nomen) {
#define N 2
    nomen_t nomens[N] = {
        {2, 2},
        {1, 1},
    };
    polinom_t *head = arr2list(N, nomens);
    head = ddx(head);

    nomen_t etalon_nomens[N] = {
        {4, 1},
        {1, 0}
    };
    polinom_t *etalon_head = arr2list(N, etalon_nomens);
    ck_assert_int_eq(ck_assert_polinom_eq(head, etalon_head), 0);
    free_polinom(etalon_head);
    free_polinom(head);
#undef N
} END_TEST

// Полином из свободного члена
START_TEST(polinom_with_free_nomen) {
    nomen_t nomens = {4, 0};
    polinom_t *head = nomen_create(&nomens);
    ck_assert_ptr_nonnull(head);
    head = ddx(head);
    ck_assert_ptr_null(head);
} END_TEST

Suite *ddx_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___DDX___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, std_polinom);
    tcase_add_test(tc_pos, polinom_without_free_nomen);
    tcase_add_test(tc_pos, polinom_with_free_nomen);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование sum
//----------------------------------------------------------

START_TEST(eq_polinoms_sum) {
#define N 3
    nomen_t nomens1[N] = {
        {2, 2},
        {1, 1},
        {1, 0}
    };
    polinom_t *head1 = arr2list(N, nomens1);

    nomen_t nomens2[N] = {
        {2, 2},
        {1, 1},
        {1, 0}
    };
    polinom_t *head2 = arr2list(N, nomens2);

    head1 = sum(head1, &head2);

    nomen_t etalon_nomens[N] = {
        {4, 2},
        {2, 1},
        {2, 0}
    };
    polinom_t *etalon_head = arr2list(N, etalon_nomens);
    ck_assert_int_eq(ck_assert_polinom_eq(head1, etalon_head), 0);
    free_polinom(etalon_head);
    free_polinom(head1);
    free_polinom(head2);
#undef N
} END_TEST

// Один полном пустой
START_TEST(one_null_polinom) {
#define N 2
    nomen_t nomens1[N] = {
        {2, 2},
        {1, 1},
    };
    polinom_t *head1 = arr2list(N, nomens1);

    polinom_t *head2 = NULL;

    head1 = sum(head1, &head2);

    // Ожидаем, что результат равен первому полиному
    nomen_t etalon_nomens1[N] = {
        {2, 2},
        {1, 1},
    };
    polinom_t *etalon_head1 = arr2list(N, etalon_nomens1);

    ck_assert_polinom_eq(head1, etalon_head1);

    free_polinom(etalon_head1);
    free_polinom(head1);
#undef N
} END_TEST

// Полиномы без совпадающих степеней
START_TEST(diff_polinoms) {
#define N 2
    nomen_t nomens1[N - 1] = {{2, 2}};
    polinom_t *head1 = arr2list(N - 1, nomens1);
    ck_assert_ptr_nonnull(head1);

    nomen_t nomens2[N - 1] ={{3, 3}};
    polinom_t *head2 = arr2list(N - 1, nomens2);
    ck_assert_ptr_nonnull(head2);

    head1 = sum(head1, &head2);

    // Ожидаем, что результат содержит все члены обоих полиномов
    nomen_t etalon_nomens[N] = {
        {3, 3},
        {2, 2}
    };
    polinom_t *etalon_head = arr2list(N - 1, etalon_nomens);
    ck_assert_polinom_eq(head1, etalon_head);

    free_polinom(etalon_head);
    free_polinom(head1);
    free_polinom(head2);
} END_TEST

Suite *sum_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___SUM___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, eq_polinoms_sum);
    tcase_add_test(tc_pos, one_null_polinom);
    tcase_add_test(tc_pos, diff_polinoms);

    suite_add_tcase(s, tc_pos);

    return s;
}

// Тестирование dvd
//----------------------------------------------------------

// Только нечетные степеня
START_TEST(odd_powers) {
#define N 2
    nomen_t nomens1[N] = {
        {3, 3},
        {1, 1}
    };
    polinom_t *head1 = arr2list(N, nomens1);

    polinom_t *head2 =  dvd(&head1);
    ck_assert_ptr_null(head1);
    nomen_t etalon_nomens[N] = {
        {3, 3},
        {1, 1}
    };
    polinom_t *etalon_head = arr2list(N, etalon_nomens);
    ck_assert_int_eq(ck_assert_polinom_eq(head2, etalon_head), 0);
    free_polinom(etalon_head);
    free_polinom(head2);
    free_polinom(head1);
#undef N
} END_TEST

// Только четные степеня
START_TEST(even_powers) {
#define N 2
    nomen_t nomens1[N] = {
        {4, 4},
        {2, 2}
    };
    polinom_t *head1 = arr2list(N, nomens1);

    polinom_t *head2 =  dvd(&head1);
    ck_assert_ptr_null(head2);
    nomen_t etalon_nomens[N] = {
        {4, 4},
        {2, 2}
    };
    polinom_t *etalon_head = arr2list(N, etalon_nomens);
    ck_assert_int_eq(ck_assert_polinom_eq(head1, etalon_head), 0);
    free_polinom(etalon_head);
    free_polinom(head2);
    free_polinom(head1);
#undef N
} END_TEST

// Степени разных четностей
START_TEST(mult_powers) {
#define N 2
    nomen_t nomens1[N] = {
        {4, 4},
        {3, 3}
    };
    polinom_t *head1 = arr2list(N, nomens1);

    polinom_t *head2 =  dvd(&head1);
    nomen_t etalon_nomens1[N / 2] = {{4, 4}};
    polinom_t *etalon_head1 = arr2list(N / 2, etalon_nomens1);

    nomen_t etalon_nomens2[N / 2] = {{3, 3}};
    polinom_t *etalon_head2 = arr2list(N / 2, etalon_nomens2);
    ck_assert_int_eq(ck_assert_polinom_eq(head1, etalon_head1), 0);
    ck_assert_int_eq(ck_assert_polinom_eq(head2, etalon_head2), 0);
    free_polinom(etalon_head2);
    free_polinom(etalon_head1);
    free_polinom(head2);
    free_polinom(head1);
} END_TEST

Suite *dvd_suite(void) {
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n___DVD___");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, odd_powers);
    tcase_add_test(tc_pos, even_powers);
    tcase_add_test(tc_pos, mult_powers);

    suite_add_tcase(s, tc_pos);

    return s;

}
