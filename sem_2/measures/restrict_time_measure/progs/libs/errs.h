#ifndef ERRS_H
#define ERRS_H

#include <stddef.h>

#define OK 0
#define ERR_ARGS_CNT 1
#define ERR_ARG 2
#define ERR_ARG_RANGE 3

/**
 * @brief Функция проверки аргумента
 * 
 * @param arg - аргумент
 * @return Код ошибки
 */
int check_arg(char *arg);

/**
 * @brief Функция проверки диапазона аргумента и записи аргументав размер матрицы
 * @param[in] arg - аргумент 
 * @param[out] n - размер матрицы
 * @return Код ошибки
 */
int check_arg_range(char *arg, size_t *n);

#endif // !ERRS_H
