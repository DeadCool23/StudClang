#ifndef ERRS_H
#define ERRS_H

#include <stdio.h>

/**
 * @def OK
 * Положительное окончание программы
 * @def ERR_PARAM
 * Ошибка параметров
 * @def ERR_KEY
 * Ошибка ключа
 * @def ERR_FILE
 * Ошибка открытия файла
 * @def ERR_NUM_PARAM
 * Ошибка параметра числа
 * @def ERR_NUM_RANGE
 * Ошибка диапазона числа параметра
 * @def ERR_DATA
 * Ошибка информации
 * @def ERR_EMPTY_FILE
 * Ошибка пустого файла
 */
#define OK 0
#define ERR_PARAM 1
#define ERR_KEY 2
#define ERR_FILE 3
#define ERR_FILE_WORK 4
#define ERR_NUM_PARAM 5
#define ERR_NUM_RANGE 6
#define ERR_DATA 7
#define ERR_EMPTY_FILE 8

/**
 * @def ERR_CHECK
 * Проверка кода ошибки
 */
#define ERR_CHECK(err) if (err != OK) return err

/**
 * @brief Функция проверки файла
 * @param[in] filename - имя файла
 * @return Код ошибки
 */
int check_file(const char *filename);

/**
 * @brief Функция проверки числа параметра
 *
 * @param[in] num_str - введенное число
 * @param[out] number - число
 * @return Код ошибки
 */
int check_num(const char *num_str, size_t *number);

#endif //ERRS_H
