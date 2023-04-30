#ifndef TESTING_H
#define TESTING_H

#include <stddef.h>

/**
 * @def TEST_COUNT
 * Количество тестов
 * @def STR_LEN
 * Максимальная длина строки
 */
#define TEST_COUNT 4
#define STR_LEN (256 + 1)

/**
 * @brief Процедура сравнения работы функций с их аналогами
 * @param[out] errors - количество найденных ошибок
 */
void diff_sting(size_t *errors);

/**
 * @brief Процедура сравнения работы strpbrk с my_strpbrk
 * @param[out] errs - количество найденных ошибок
 */
void diff_strpbrk(size_t *errs);

/**
 * @brief Процедура сравнения работы strspn с my_strspn
 * @param[out] errs - количество найденных ошибок
 */
void diff_strspn(size_t *errs);

/**
 * @brief Процедура сравнения работы strcspn с my_strcspn
 * @param[out] errs - количество найденных ошибок
 */
void diff_strcspn(size_t *errs);

/**
 * @brief Процедура сравнения работы strchr с my_strchr
 * @param[out] errs - количество найденных ошибок
 */
void diff_strchr(size_t *errs);

/**
 * @brief Процедура сравнения работы strrchr с my_strrchr
 * @param[out] errs - количество найденных ошибок
 */
void diff_strrchr(size_t *errs);

#endif
