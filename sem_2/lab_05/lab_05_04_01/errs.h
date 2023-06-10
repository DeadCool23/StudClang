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
 * @def ERR_READ
 * Ошибка чтения
 */
#define OK 0
#define ERR_PARAM 1
#define ERR_KEY 53
#define ERR_FILE 3
#define ERR_FILE_WORK 4
#define ERR_DATA 5
#define ERR_READ 6

/**
 * @def ERR_CHECK
 * Проверка кода ошибки
 * @def CHECK_FILES
 * Проверка открытия файлов
 * @def CHECK_FILE
 * Проверка открытия файла
 */
#define ERR_CHECK(err) if (err != OK) return err
#define CHECK_FILES(file1, file2) if (file1 == NULL || file2 == NULL) return ERR_FILE
#define CHECK_FILE(file) if (file == NULL) return ERR_FILE

#endif //ERRS_H
