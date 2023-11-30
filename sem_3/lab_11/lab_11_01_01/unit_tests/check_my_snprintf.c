#include "check_my_snprintf.h"
#include "my_snprintf.h"

#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wformat-security"

// Тестирование my_snprintf
// ==========================================================================

// Тестирование спецификатора %lo
// ------------------------------------------------------------------------

// Проверка правильности перевода десятичных чисел в восьмеричную систему счисления
START_TEST(lo_is_right_translate) {
#define BUF_LEN 10
    size_t maxlen = 5;
    char *format = "%lo";
    unsigned long num = 8;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Переполнение ввода в строку
START_TEST(lo_num_overflow) {
#define BUF_LEN 10
    size_t maxlen = 2;
    char *format = "%lo";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Запись числа с форматной строкой
START_TEST(lo_comb_with_str) {
#define BUF_LEN 100
    size_t maxlen = 50;
    char *format = "oct: %lo";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Тестирование спецификатора %lx
// ------------------------------------------------------------------------

// Проверка правильности перевода десятичных чисел в восьмеричную систему счисления
START_TEST(lx_is_right_translate) {
#define BUF_LEN 10
    size_t maxlen = 5;
    char *format = "%lx";
    unsigned long num = 8;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Переполнение ввода в строку
START_TEST(lx_num_overflow) {
#define BUF_LEN 10
    size_t maxlen = 2;
    char *format = "%lx";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Запись числа с форматной строкой
START_TEST(lx_comb_with_str) {
#define BUF_LEN 100
    size_t maxlen = 50;
    char *format = "oct: %lx";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Тестирование спецификатора %lu
// ------------------------------------------------------------------------

// Проверка правильности перевода десятичных чисел в восьмеричную систему счисления
START_TEST(lu_is_right_translate) {
#define BUF_LEN 10
    size_t maxlen = 5;
    char *format = "%lu";
    unsigned long num = 8;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Переполнение ввода в строку
START_TEST(lu_num_overflow) {
#define BUF_LEN 10
    size_t maxlen = 2;
    char *format = "%lu";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Запись числа с форматной строкой
START_TEST(lu_comb_with_str) {
#define BUF_LEN 100
    size_t maxlen = 50;
    char *format = "oct: %lu";
    unsigned long num = 128;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Тестирование спецификатора %c
// ------------------------------------------------------------------------

// Запись символа
START_TEST(char_write) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%c";
    char str = 'a';
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Тестирование спецификатора %d
// ------------------------------------------------------------------------

// Запись положиельного числа
START_TEST(pos_num) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%d";
    int str = 10;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Запись отрицательного числа
START_TEST(neg_num) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%d";
    int str = -10;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Запись 0
START_TEST(zero_num) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%d";
    int str = 0;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Тестирование спецификатора %s
// ------------------------------------------------------------------------

// Строка - NULL
START_TEST(null_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = NULL;
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Английское строка
START_TEST(english_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = "Hello";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Русское строка
START_TEST(russian_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = "Рус";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Пустая строка
START_TEST(empty_spec_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = "";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Строка комбинирована с форматной строкой
START_TEST(s_comb_with_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "str %s";
    char *str = "nun";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Переполнения ввода в строку
START_TEST(overflow_write_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = "Aaaaaaaaaaaa";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Строка специа
START_TEST(special_symbols_str) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%s";
    char *str = "%%\"\n\t\a\\";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Общие тесты
// ------------------------------------------------------------------------

// Пустая строка
START_TEST(empty_str) {
#define BUF_LEN 10
    size_t maxlen = 2;
    char *format = "";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format);
    int etalon_ret = snprintf(etalon_buf, maxlen, format);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
} END_TEST

// Английское слово
START_TEST(english_words) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "english";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format);
    int etalon_ret = snprintf(etalon_buf, maxlen, format);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Русское слово
START_TEST(russian_words) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "Рус";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format);
    int etalon_ret = snprintf(etalon_buf, maxlen, format);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Специальные символы
START_TEST(special_symbols) {
#define BUF_LEN 10
    size_t maxlen = 10;
    char *format = "%%\"\n\t\a\\";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format);
    int etalon_ret = snprintf(etalon_buf, maxlen, format);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Переполнение формата
START_TEST(overflow_write_format) {
#define BUF_LEN 10
    size_t maxlen = 5;
    char *restrict format = "njnwbvuwouvwb";
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format);
    int etalon_ret = snprintf(etalon_buf, maxlen, format);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

// Формат со всеми возможными спецификаторами
START_TEST(format_with_diff_spec) {
#define BUF_LEN 100
    size_t maxlen = 50;
    char *format = "str %s %lx";
    unsigned long num = 1;
    char *str = "World"; 
    char buf[BUF_LEN] = "", etalon_buf[BUF_LEN] = "";
    int ret = my_snprintf(buf, maxlen, format, str, num);
    int etalon_ret = snprintf(etalon_buf, maxlen, format, str, num);

    ck_assert_int_eq(ret, etalon_ret);
    ck_assert_str_eq(buf, etalon_buf);
#undef BUF_LEN
}

Suite *my_snprintf_suite(void) {
    Suite *s;
    TCase *tc_lo, *tc_lu, *tc_lx;
    TCase *tc_str, *tc_all, *tc_char, *tc_int;

    s = suite_create("\n___MY_SNPRINTF___");

    tc_lo = tcase_create(" lo ");
    tc_lu = tcase_create(" lu ");
    tc_lx = tcase_create(" lx ");
    tc_int = tcase_create(" int ");
    tc_char = tcase_create(" char ");
    tc_str = tcase_create(" str ");
    tc_all = tcase_create(" all ");

    // Тесты %lo
    tcase_add_test(tc_lo, lo_num_overflow);
    tcase_add_test(tc_lo, lo_comb_with_str);
    tcase_add_test(tc_lo, lo_is_right_translate);

    // Тесты %lx
    tcase_add_test(tc_lx, lx_num_overflow);
    tcase_add_test(tc_lx, lx_comb_with_str);
    tcase_add_test(tc_lx, lx_is_right_translate);

    // Тесты %lu
    tcase_add_test(tc_lu, lu_num_overflow);
    tcase_add_test(tc_lu, lu_comb_with_str);
    tcase_add_test(tc_lu, lu_is_right_translate);

    // Тесты %d
    tcase_add_test(tc_int, pos_num);
    tcase_add_test(tc_int, neg_num);
    tcase_add_test(tc_int, zero_num);

    // Тесты %c
    tcase_add_test(tc_char, char_write);

    // Тесты %s
    tcase_add_test(tc_str, null_str);
    tcase_add_test(tc_str, english_str);
    tcase_add_test(tc_str, russian_str);
    tcase_add_test(tc_str, empty_spec_str);
    tcase_add_test(tc_str, s_comb_with_str);
    tcase_add_test(tc_str, overflow_write_str);
    tcase_add_test(tc_str, special_symbols_str);

    // Общие тесты
    tcase_add_test(tc_all, empty_str);
    tcase_add_test(tc_all, english_words);
    tcase_add_test(tc_all, russian_words);
    tcase_add_test(tc_all, special_symbols);
    tcase_add_test(tc_all, overflow_write_format);
    tcase_add_test(tc_all, format_with_diff_spec);

    suite_add_tcase(s, tc_lo);
    suite_add_tcase(s, tc_lu);
    suite_add_tcase(s, tc_lx);
    suite_add_tcase(s, tc_int);
    suite_add_tcase(s, tc_char);
    suite_add_tcase(s, tc_str);
    suite_add_tcase(s, tc_all);

    return s;
}
